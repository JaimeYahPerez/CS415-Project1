CXX = g++
CXXFLAGS = -std=c++17 -O2

TARGET = CS415-Project1

SOURCES = main.cpp \
		  fib_euclid.cpp \
          exponentiation.cpp \
          insertionSort.cpp \
          selectionsort.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean