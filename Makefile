all: mkdir_bin
	+$(MAKE) -C src/interfaces/blocks
	+$(MAKE) -C src/interfaces/levels
	+$(MAKE) -C src/interfaces
	+$(MAKE) -C src/interfaces/levels/test

mkdir_bin:
	mkdir -p bin