#include "Headers.hpp"

    int WIDTH = 600;   // Change This _X To change The Width Of The Window
	int HEIGHT = 600;   // Change This _Y To Change The Height Of The Window

int z = 0;
int iterations = 1000;

int value(int x, int y){
    std::complex<float> point((float)x/WIDTH-1.5, (float)y/HEIGHT-0.5);
    std::complex<float> z(0,0);

    int nb_iter = 0;
    while(abs(z) < 2 && nb_iter <= 100){
        z = z*z + point;
        nb_iter++;
    }

    if(nb_iter == 100){
        glColor3f(0,0,0);
    }else{
        float angle = nb_iter*0.1f;
        float r = 0.5 + 0.5*sin(angle);
        float g = 0.5 + 0.5*sin(angle+2.1);
        float b = 0.5+ 0.5*sin(angle+4.2);
        glColor3f(r,g,b);
        glVertex2f(x,y);
    }
    
    if(nb_iter < 40)
        return (255*nb_iter)/40;
    else
        return 0;
}

void Create_Mandelbrot(){
    std::ofstream Image("Mandelbrot_Output.ppm");
    if(Image.is_open()){
        Image << "P3\n" << WIDTH << " " << HEIGHT << " 255\n";            
        glPointSize(1);
        glBegin(GL_POINTS);
        for(int i = 0 ; i < WIDTH; i++){
            for(int j = 0 ; j < HEIGHT; j++){
                int val = value(i,j);
                Image << val << ' ' << 0 << ' ' << 0 << "\n";
            }
        }
        glEnd();

        Image.close();
        std::cout << "\nMandelbrot Calculated.";

    }
}

void display(){
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    Create_Mandelbrot();

    glFlush();

}


Application::Application(std::string title){

    glutInitWindowPosition(300, 200);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);

    char Parse_Title[title.size() - 1]; // PARSING STRING TO CHAR method
    strcpy(Parse_Title, title.c_str());

    glutCreateWindow(Parse_Title);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glEnable(GL_LINE_STIPPLE); 
    glutDisplayFunc(display);
    
    glutMainLoop();

}

Application::~Application(){
	std::cout << "Project 2 Shutting Down...";
    delete this;
}