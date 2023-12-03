CC = g++
CFLAGS = -Wall -std=c++11
LIBS = `pkg-config --cflags --libs opencv4`

all: FiltroImagen_Thread
FiltroImagen_Thread: FiltroImagen_Thread.cpp
	$(CC) $(CFLAGS) -o FiltroImagen_Thread FiltroImagen_Thread.cpp $(LIBS)
clean:
	rm -f FiltroImagen_Thread
