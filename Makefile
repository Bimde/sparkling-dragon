all: mkdir_bin clean_bin
	+$(MAKE) -C src/interfaces/blocks
	+$(MAKE) -C src/interfaces/levels
	+$(MAKE) -C src/interfaces
	+$(MAKE) -C src/ui

mkdir_bin:
	mkdir -p bin

clean_bin:
	rm bin/*.o

make_test:
	all
	+$(MAKE) -C src/interfaces/levels/test