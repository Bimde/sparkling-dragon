MAIN_EXEC = quadris
TEST_EXEC = test
TO_TEST_EXEC = g++ -o ${TEST_EXEC} bin/*.o -lX11 -pthread && chmod 777 ${TEST_EXEC}
TO_MAIN_EXEC = g++ -o ${MAIN_EXEC} bin/*.o -lX11 -pthread && chmod 777 ${MAIN_EXEC}

all: mkdir_bin clean_bin inter_all main_only

inter_all:
	+$(MAKE) -C src/interfaces/blocks
	+$(MAKE) -C src/interfaces/levels
	+$(MAKE) -C src/interfaces
	+$(MAKE) -C src/ui

mkdir_bin:
	mkdir -p bin

clean_bin:
	rm -f bin/*.o

test: inter_all
	+$(MAKE) -C src/interfaces/levels/test
	+$(MAKE) -C src/testing
	${TO_TEST_EXEC}

test_only:
	+$(MAKE) -C src/interfaces/levels/test
	+$(MAKE) -C src/ui/test
	+$(MAKE) -C src/testing
	${TO_TEST_EXEC}

main_only:
	+$(MAKE) -C src
	${TO_MAIN_EXEC}