CC = g++
CFLAGS = `pkg-config --cflags --libs opencv4`
LIBS =-Wall -std=c++11 -fopenmp -I /usr/include/opencv4

all: FiltroImagen_OpenMP

FiltroImagen_OpenMP: FiltroImagen_OpenMP.cpp
	$(CC) $(CFLAGS) -o FiltroImagen_OpenMP FiltroImagen_OpenMP.cpp $(LIBS)

clean:
	rm -f FiltroImagen_OpenMP

