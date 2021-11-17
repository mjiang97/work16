all: work16.o
	gcc -o program work16.c
	
work16.o:
	gcc -c work16.c
	
run:
	./program

clean:
	rm *.o
