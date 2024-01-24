code : codage.o decodage.o code.o generate.o
	gcc -o code codage.o decodage.o code.o generate.o

codage.o : codage.c
	gcc -o codage.o -c codage.c
	
decodage.o : decodage.c
	gcc -o decodage.o -c decodage.c

code.o : code.c
	gcc -o code.o -c code.c 

generate.o : generate.c
	gcc -o generate.o -c generate.c

clean :
	rm -f *.o -f code
