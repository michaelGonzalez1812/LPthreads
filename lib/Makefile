libraries: liblpthread.a liblpthread_mutex.a libpackage.a libscheduler.a libband.a

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

libband.a: band.o
	#Create an static library
	ar rv lib/libband.a lib/band.o lib/package.o lib/scheduler.o
	ranlib lib/libband.a

band.o: lib/band.c include/band.h
	gcc -c lib/band.c -o lib/band.o -Iinclude -Llib

libpackage.a: package.o
	#Create an static library
	ar rv lib/libpackage.a lib/package.o
	ranlib lib/libpackage.a

package.o: lib/package.c include/package.h
	gcc -c lib/package.c -o lib/package.o -Iinclude -Llib

libscheduler.a: scheduler.o
	#Create an static library
	ar rv lib/libscheduler.a lib/scheduler.o
	ranlib lib/libscheduler.a

scheduler.o: lib/scheduler.c include/scheduler.h
	gcc -c lib/scheduler.c -o lib/scheduler.o -Iinclude -Llib