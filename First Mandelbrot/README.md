# First Mandelbrot
#### Colorful Mandelbrot generation 

### Description:
This project generates a mandelbrot with various color formations using the sinewave function with the glut.h library. An output image is also provided as a .ppm file. The dependencies are also provided, in order to give the user ease of use <br/>
<br/>

### How to Compile: <br/>
```
> g++ Main.cpp Application.cpp -o run -I..\dependencies\include -L..\dependencies\lib -lopengl32 -lglut32 -lglu32 -lgdi32 -luser32 -lkernel32 -lShell32
> run
```
### Compilation Output: <br/>
<img src="https://github.com/ChilledFerrum/Graphics-Art/blob/88930033db0e7d3b0e36517cbfbc84d6cfe1b9f1/First%20Mandelbrot/ColorfulMandelbrot.png"/>


### Compilation .ppm Output: <br/>
<img src="https://github.com/ChilledFerrum/Graphics-Art/blob/88930033db0e7d3b0e36517cbfbc84d6cfe1b9f1/First%20Mandelbrot/Mandelbrot_Output.jpg"/>
