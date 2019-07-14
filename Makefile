all: mkdir_bin
	+$(MAKE) -C src/interfaces/blocks
	+$(MAKE) -C src/interfaces/levels
	+$(MAKE) -C src/interfaces
	+$(MAKE) -C src/interfaces/levels/test
	+$(MAKE) -C src/ui
	g++ -o final bin/*.o -lX11

mkdir_bin:
	mkdir -p bin