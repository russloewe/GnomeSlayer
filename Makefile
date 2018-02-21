CC=gcc
CFLAGS= -g
LIBS= `sdl-config --libs` -lSDL
OBJ=  init.o input.o display.o gameobjects.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ) main.o
	gcc -o main $^ $(CFLAGS) $(LIBS)
	
test: $(OBJ) test.o test_suit.o
	gcc -o test $^ $(CFLAGS) $(LIBS)
	
runtest: test
	./test
	
uptest: test
	scp ./test russell.loewe@syccuxas01.pcc.edu:~/project/
	ssh -X russell.loewe@syccuxas01.pcc.edu "cd ~/project && ./test"
	
upmain: main
	scp ./main russell.loewe@syccuxas01.pcc.edu:~/project/
	
clean:
	rm -rf *o
