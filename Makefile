MAIN_EXEC = quadris_main
TEST_EXEC = final
TO_TEST_EXEC = g++ -o ${TEST_EXEC} bin/*.o -lX11
TO_MAIN_EXEC = g++ -o ${MAIN_EXEC} bin/*.o -lX11

all: mkdir_bin clean_bin
	+$(MAKE) -C src/interfaces/blocks
	+$(MAKE) -C src/interfaces/levels
	+$(MAKE) -C src/interfaces
	+$(MAKE) -C src/ui

inter_only:
	+$(MAKE) -C src/interfaces

mkdir_bin:
	mkdir -p bin

clean_bin:
	rm bin/*.o

test: all
	+$(MAKE) -C src/interfaces/levels/test
	+$(MAKE) -C src/testing
	${TO_TEST_EXEC}

test_only:
	+$(MAKE) -C src/interfaces/levels/test
	+$(MAKE) -C src/testing
	${TO_TEST_EXEC}

main: all
	+$(MAKE) -C src
	${TO_MAIN_EXEC}

main_only:
	+$(MAKE) -C src
	${TO_MAIN_EXEC}