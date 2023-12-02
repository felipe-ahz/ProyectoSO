CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -fopenmp
LIBS = `pkg-config --cflags --libs opencv4`

TARGET = Paralel_OpenMP
SOURCE = Paralel_OpenMP.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f $(TARGET)
