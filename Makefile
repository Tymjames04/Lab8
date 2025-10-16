CC=gcc
CFLAGS= -c -Wall

all: nfl temps

nfl: nfl.o
	$(CC) nfl.o -o nfl
	rm -rf *.o

temps: temps.o
	$(CC) temps.o -o temps
	rm -rf *.o

nfl.o: nfl.c
	$(CC) $(CFLAGS) nfl.c

temps.o: temps.c
	$(CC) $(CFLAGS) temps.c

clean:

