CC = g++
CFLAGS = -Wall -std=c++11
LIBS = `pkg-config --cflags --libs opencv4`

all: FiltroImagen_Secuencial
FiltroImagen_Secuencial: FiltroImagen_Secuencial.cpp
	$(CC) $(CFLAGS) -o FiltroImagen_Secuencial FiltroImagen_Secuencial.cpp $(LIBS)
clean:
	rm -f FiltroImagen_Secuencial
