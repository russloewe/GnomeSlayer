CC=gcc
CFLAGS= -g --std=c99
LIBS=    `sdl2-config --libs`  -l:libSDL2.a    
OBJ=  input.o display.o gameobjects.o

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ) main.o
	gcc -o main $^ -g $(LIBS)
	
test-graphics: $(OBJ) test_graphics.o
	gcc -o test_graphics $^ -g $(LIBS)
	
uptest: test
	scp ./test russell.loewe@syccuxas01.pcc.edu:~/project/
	ssh -X russell.loewe@syccuxas01.pcc.edu "cd ~/project && ./test"
	
upmain: main
	scp ./main russell.loewe@syccuxas01.pcc.edu:~/project/
	
clean:
	rm -rf *o
