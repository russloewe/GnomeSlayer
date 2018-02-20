all: main.o init.o input.o
	gcc  main.o init.o input.o -o main `sdl-config --libs` -lSDL

runtest: test
	./test
	
test: test.o test_suit.o init.o input.o
	gcc init.o input.o test.o test_suit.o -o test `sdl-config --libs` -lSDL
	
test.o: test.c
	gcc -c test.c
	
test_suit.o: test_suit.c
	gcc -c test_suit.c
	
main.o: main.c
	gcc -c main.c
	
init.o: init.c
	gcc -c init.c
	
input.o: input.c
	gcc -c input.c
	
uptest: test
	scp ./test russell.loewe@syccuxas01.pcc.edu:~/project/
	ssh -X russell.loewe@syccuxas01.pcc.edu "~/project/test"
	
upmain: main
	scp ./main russell.loewe@syccuxas01.pcc.edu:~/project/
	
clean:
	rm -rf *o
