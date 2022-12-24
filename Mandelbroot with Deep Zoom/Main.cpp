#include "Headers.hpp"

int main(int argc, char** argv){
    std::cout << "Welcome to Project 2\n" << std::endl << "Running...";

    glutInit(&argc, argv);
    Application *App = new Application("Mandelbrot");
    
    // Exits on its own :( can't process code after the definition of App
    // FreeGlut Library offers functions that can shutdown the App and exit loop whenever
}