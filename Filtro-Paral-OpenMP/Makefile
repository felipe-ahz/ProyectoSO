CC = g++
LIBS = `pkg-config --cflags --libs opencv4`
CFLAGS = -Wall -std=c++11 -fopenmp

all: FiltroImagen_OpenMP

FiltroImagen_OpenMP: FiltroImagen_OpenMP.cpp
	$(CC) $(CFLAGS) -o FiltroImagen_OpenMP FiltroImagen_OpenMP.cpp $(LIBS)

clean:
	rm -f FiltroImagen_OpenMP

