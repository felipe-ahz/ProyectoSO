CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = $(shell pkg-config --cflags --libs opencv4)

TARGET = FiltroImagen_Secuencial
SRC = FiltroImagen_Secuencial.cpp

all: $(TARGET)

$(TARGET): $(SRC)
    $(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
    rm -f $(TARGET)
