CC=gcc
CFLAGS= -g --std=c99
LIBS=    `sdl2-config --libs`  -l:libSDL2.a    
OBJ=  input.o graphics.o gameobjects.o

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ) main.o
	gcc -o main $^ -g $(LIBS)
	
test-graphics: $(OBJ) test_graphics.o
	gcc -o test_graphics $^ -g $(LIBS)
	
test-gameobjects: $(OBJ) test_gameobjects.o
	gcc -o test_gameobjects $^ -g $(LIBS)
	
test-input: $(OBJ) test_input.o
	gcc -o test_input $^ -g $(LIBS)
	
test-maps: $(OBJ) test_maps.o
	gcc -o test_maps $^ -g $(LIBS)
	
clean:
	rm -rf *o
