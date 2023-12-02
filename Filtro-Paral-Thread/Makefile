CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pthread
LDFLAGS = $(shell pkg-config --cflags --libs opencv4)

TARGET = FiltroImagen_Paralelo_Thread
SRC = FiltroImagen_Paralelo_Thread.cpp

all: $(TARGET)

$(TARGET): $(SRC)
    $(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
    rm -f $(TARGET)
