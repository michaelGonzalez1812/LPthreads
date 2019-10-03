libraries: liblpthread.a

liblpthread.a: lpthread.o
	#Create an static library
	ar rv lib/liblpthread.a lib/lpthread.o
	ranlib lib/liblpthread.a

lpthread.o: lib/lpthread.c include/lpthread.h
	gcc -c lib/lpthread.c -o lib/lpthread.o -Iinclude -Llib