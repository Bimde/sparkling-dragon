#ifndef INTERFACES_BLOCK_H
#define INTERFACES_BLOCK_H

class Block {
	int score;
	char type;
	
  public:
  	Block(int score, char type);
  	virtual ~Block() = 0;
  	
  	int score();
  	char type();
};

#endif