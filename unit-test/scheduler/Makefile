all: round_robin short_job_first fifo priority

flags = -g -Llib -Iinclude -lscheduler

round_robin: unit-test/scheduler/round_robin.c
	gcc -o unit-test/build/round_robin unit-test/scheduler/round_robin.c $(flags)

short_job_first: unit-test/scheduler/short_job_first.c
	gcc -o unit-test/build/short_job_first unit-test/scheduler/short_job_first.c $(flags)

fifo: unit-test/scheduler/fifo.c
	gcc -o unit-test/build/fifo unit-test/scheduler/fifo.c $(flags)

priority: unit-test/scheduler/priority.c
	gcc -o unit-test/build/priority unit-test/scheduler/priority.c $(flags)