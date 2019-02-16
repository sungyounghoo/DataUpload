CXX=g++
CFLAGS=-c -Wall -I.
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=test.out

all : clean $(SOURCES) $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CXX) -lrt $(OBJECTS) -o $@
.cpp.o:
	   $(CXX) $(CFLAGS) $< -o $@
clean :
	rm -f *.o *.out
