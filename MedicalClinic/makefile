CC = g++
CFLAGS = -std=c++11 -g -Wall -I include
TARGET = bin/runner
DEPS = include/*.h
OBJ = build/Interface.o build/Clinic.o build/Doctor.o build/Patient.o build/main.o

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