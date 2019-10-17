all: create-join mutex_test yield_test

flags = -Llib -Iinclude -llpthread -llpthread_mutex -g

create-join: unit-test/lpthread/create-join.c
	gcc -o unit-test/build/create-join unit-test/lpthread/create-join.c $(flags)

mutex_test: unit-test/lpthread/mutex_test.c
	gcc -o unit-test/build/mutex_test unit-test/lpthread/mutex_test.c $(flags)

yield_test: unit-test/lpthread/yield_test.c
	gcc -o unit-test/build/yield_test unit-test/lpthread/yield_test.c $(flags)