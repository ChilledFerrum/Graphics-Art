#include "Headers.hpp"
#include <sys/time.h>
#include <cmath>

/* The argument now should be a double (not a pointer to a double) */
#define GET_TIME(now) { \
   struct timeval t; \
   gettimeofday(&t, NULL); \
   now = t.tv_sec + t.tv_usec/1000000.0; \
}

int WIDTH = 800;   // Change This _X To change The Width Of The Window
int HEIGHT = 800;   // Change This _Y To Change The Height Of The Window

int nb_iter;
int max_iter = 256;


float r;
float g;
float b;
float angle;

double iter = 1;
double zoom = 0.7;
double X_location = 0.0;
double Y_location = 0.0;
float modifier = 0.3;
double multiplier = 0;
double zx,zy,rx,ry, as = -(HEIGHT/(double)WIDTH)*(1.5 + 2.5)/2;
double y_min = -as, pw = (1.5 + 2.5) / WIDTH,
                    ph = (as - y_min) / HEIGHT;
double zxold, zyold;
int x, y;

void value(int x, int y){
    ry = (y_min + y *ph)*zoom + Y_location;
    rx = (-2.5 + x * pw)*zoom + X_location;
    zx = .0; zy = .0;

    for(nb_iter = 0 ; nb_iter < max_iter && ((zx*zx + zy*zy) < 100); nb_iter++){
        zx = zx*zx - zy*zy +rx;
        zy = 2*zxold*zy + ry;
        zxold = zx; zyold = zy*zy;
    }

    if(nb_iter == max_iter){
        glColor3f(0,0,0);
    }else if(nb_iter <= 15){
        angle = nb_iter*0.2f;
        r = 0.2;
        g = 0.5;
        b = modifier + 0.5*sin(angle);
        glColor3f(r,g,b);
    }else{
        angle = nb_iter*0.5f;
        r = 0.1;
        g = modifier + 0.5*sin(angle + 2.1);
        b = modifier + 0.5*sin(angle + 4.2);
        glColor3f(r,g,b);
    }
    glVertex2f(x,y);
}

void Create_Mandelbrot(){         
    glPointSize(1);
    glBegin(GL_POINTS);
    double startime,finishtime;
    GET_TIME(startime);
    for(int j = 0 ; j < WIDTH * HEIGHT; j++){
        x = j% WIDTH;
        y = j / WIDTH;
        value(x,y);
    }
    glEnd();
    GET_TIME(finishtime);
    // std::cout << "Render Time: " << finishtime - startime << std::endl;
    // std::cout << "\nMandelbrot Calculated.";
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    Create_Mandelbrot();

    glFlush();

}

void keyboard(unsigned char key,int x1, int y1)
{
    if(key=='q')
    {   
        iter += 1;
        zoom = 1/pow(2, iter);
        
    }
    if(key=='e')
    {
        iter --;
        zoom = 1/pow(2, iter);
    }
    std::cout << "\nZoom: " << zoom << std::endl;
    if(key=='a')
    {
        X_location -= 1/pow(2, iter);
    }
    if(key=='d')
    {
        X_location += 1/pow(2, iter);
    }
    if(key == 'w'){
        Y_location -= 1/pow(2, iter);

    }
    if(key == 's'){
        Y_location += 1/pow(2, iter);
    }
    glutPostRedisplay();
}

Application::Application(std::string title){
    printf("Inputs: \nPress 'a' to move left\nPress 'd' to move right\nPress 's' to move down\nPress 'w' to move up\nPress 'q' to zoom in\nPress 'e' to zoom out\n");
    glutInitWindowPosition(700, 200);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);

    char charTitle[title.size() - 1];
    strcpy(charTitle, title.c_str());

    glutCreateWindow(charTitle);

    // Smoothing 
    glEnable( GL_POINT_SMOOTH );
    // glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glEnable(GL_LINE_STIPPLE); 
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

}

Application::~Application(){
	std::cout << "Project 2 Shutting Down...";
    delete this;
}