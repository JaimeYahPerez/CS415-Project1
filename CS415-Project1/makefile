CXX = g++
CXXFLAGS = -std=c++17 -02

TARGET = CS415-Project1

SOURCES = main.cpp exponentiation.cpp InsertionSort.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean