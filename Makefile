CC=gcc
CFLAGS= -g --std=c99 -O3 -I/home/student/russell.loewe/libs/include
LIBS=   -L/home/student/russell.loewe/libs/lib64/ `/home/student/russell.loewe/libs/bin/sdl2-config --libs`  -l:libSDL2.a

OBJ=  input.o graphics.o gameobjects.o checker.o maps.o ai.o draw.o
TESTS= test_graphics.o test_gameobjects.o test_checker.o test_ai.o test_input.o test_maps.o test.o

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ) main.o
	gcc -o main $^ -g $(LIBS)
	
test: $(OBJ) $(TESTS)
	gcc -o test $^ -g $(LIBS)
	
clean:
	rm -rf *o
