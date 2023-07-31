CC := g++
CFLAGS := -Wall -Wextra -std=c++11
LIB := libfilesearch.a
TARGET := main

all: $(TARGET)

$(TARGET): main.cpp $(LIB)
	$(CC) $(CFLAGS) -o $@ $< -L. -lfilesearch -lpthread

$(LIB): filesearchlib.cpp
	$(CC) $(CFLAGS) -c -o filesearchlib.o $<
	ar rcs $@ filesearchlib.o

clean:
	rm -f $(TARGET) $(LIB) *.o
