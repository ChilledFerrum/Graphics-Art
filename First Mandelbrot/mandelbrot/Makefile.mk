CC := g++
CFLAGS = -lopengl32 -lglut32 -lglu32 -lgdi32 -luser32 -lkernel32 -lShell32
	g++ Main.cpp Application.cpp -o run -I..\dependencies\include -L..\dependencies\lib -lopengl32 -lglut32 -lglu32 -lgdi32 -luser32 -lkernel32 -lShell32
	run
