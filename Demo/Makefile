CC = gcc
CXX = g++

TARGET = Demo

all:$(TARGET)

LIBS += -L . ../libdvp.so ../libhzd.so -lpthread -Wl,-rpath=. -std=c++11

Demo:Demo.cpp
	$(CXX) -o $@ $< $(LIBS) 


clean:
	rm Demo

