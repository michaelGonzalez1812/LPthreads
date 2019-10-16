all: compile-lib compile-transporter

compile-lib:
	make -f lib/Makefile

compile-transporter:
	make -f src/Makefile

Phony: lpthread_unit_test	
lpthread_unit_test: compile-lib
	make -f unit-test/lpthread/Makefile

Phony: clean
clean:
	rm lib/*.a lib/*.o bin/*

Phony: clean_unit_test
clean_unit_test:
	rm unit-test/build/*	

Phony: clean_all
clean_all: clean clean_unit_test
