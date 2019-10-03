all: 
	make -f lib/Makefile
	make -f src/Makefile
	

Phony: clean
clean:
	rm lib/*.a lib/*.o bin/*