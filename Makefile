EXEC = final
TO_EXEC = g++ -o ${EXEC} bin/*.o -lX11

all: mkdir_bin clean_bin
	+$(MAKE) -C src/interfaces/blocks
	+$(MAKE) -C src/interfaces/levels
	+$(MAKE) -C src/interfaces
	+$(MAKE) -C src/ui

mkdir_bin:
	mkdir -p bin

clean_bin:
	rm bin/*.o

test: all
	+$(MAKE) -C src/interfaces/levels/test
	+$(MAKE) -C src/testing
	${TO_EXEC}

test_only:
	+$(MAKE) -C src/interfaces/levels/test
	+$(MAKE) -C src/testing
	${TO_EXEC}