all:
	+$(MAKE) -C src/interfaces/blocks
	+$(MAKE) -C src/interfaces/levels
	+$(MAKE) -C src/interfaces
	+$(MAKE) -C src/interfaces/levels/test