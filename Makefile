# Adjust the next three lines if you're on a Pi
FLAVOR = nopi
INCLUDE = $(INCLUDE_NOPI)
LDFLAGS = $(LDFLAGS_NOPI)

INCLUDE_PI := -I ~/include
LDFLAGS_PI := -L ~/lib -lsense -lm
INCLUDE_NOPI := 
LDFLAGS_NOPI := -lncurses

all: clock

clock: main.o display.o
	cc -o $@ $^ $(LDFLAGS)

run: clock
	./$<.sh | ./$<

clean:
	rm -f *.o clock
	
main.o: main.c display.h
	cc -c $< $(LDFLAGS)

display.o: display.c display.h
	cc $< -c $(LDFLAGS)
