CC=gcc
CFLAGS= -g -I/home/student/russell.loewe/libs/include
LIBS=   -L/home/student/russell.loewe/libs/lib64/ `/home/student/russell.loewe/libs/bin/sdl2-config --libs`  -l:libSDL2.a    
OBJ=  init.o input.o display.o gameobjects.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ) main.o
	gcc -o main $^ -g $(LIBS)
	
test: $(OBJ) test.o test_suit.o
	gcc -o test $^ -g $(LIBS)
	
runtest: test
	./test
	
uptest: test
	scp ./test russell.loewe@syccuxas01.pcc.edu:~/project/
	ssh -X russell.loewe@syccuxas01.pcc.edu "cd ~/project && ./test"
	
upmain: main
	scp ./main russell.loewe@syccuxas01.pcc.edu:~/project/
	
clean:
	rm -rf *o
