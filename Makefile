CFLAGS=-Wall -Isrc -I/usr/local/include/SDL2
LIBS=-ldl -lSDL2
PREFIX?=/usr/local

SOURCES=$(wildcard src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TARGET=bin/pong

all: $(TARGET)

$(TARGET): build $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) $(LIBS) -o $@

build:
	mkdir -p bin

clean:
	rm -rf bin
	rm -rf src/*.o
