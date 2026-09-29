CXX = g++
CXXFLAGS = -std=c++17 -02

TARGET = CS415-Project1

SOURCES = main.cpp exponentiation.cpp InsertionSort.cpp
HEADERS = selectionsort.h fib_euclid.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean