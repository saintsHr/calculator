SRC := src/*.c
INCLUDE := -Iinclude `pkg-config --cflags --libs gtk+-3.0`
FLAGS := -mfpmath=sse -msse -msse2 -pthread

all:
	gcc $(SRC) $(INCLUDE) -o calc