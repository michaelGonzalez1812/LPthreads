libraries: liblpthread.a liblpthread_mutex.a

liblpthread.a: lpthread.o
	#Create an static library
	ar rv lib/liblpthread.a lib/lpthread.o
	ranlib lib/liblpthread.a

lpthread.o: lib/lpthread.c include/lpthread.h
	gcc -c lib/lpthread.c -o lib/lpthread.o -Iinclude -Llib

liblpthread_mutex.a: lpthread_mutex.o
	#Create an static library
	ar rv lib/liblpthread_mutex.a lib/lpthread_mutex.o
	ranlib lib/liblpthread_mutex.a

lpthread_mutex.o: lib/lpthread_mutex.c include/lpthread_mutex.h
	gcc -c lib/lpthread_mutex.c -o lib/lpthread_mutex.o -Iinclude -Llib