CC := g++
CFLAGS := -std=c++11 -g -Wall -I include
TARGET := bin/runner
DEPS := include/*.h
SOURCES := $(shell find src -type f -name *.cpp)
OBJ := $(patsubst src/%, build/%, $(patsubst %.cpp, %.o, $(SOURCES)))

$(TARGET) : $(OBJ) bin
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)
	
build/%.o : src/%.cpp $(DEPS) build
	$(CC) $(CFLAGS) -c -o $@ $<
	
build: 
	mkdir build
	
bin: 
	mkdir bin

clean: 
	rm -r build
	rm -r bin
	
.PHONY: clean