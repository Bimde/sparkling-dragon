#ifndef INTERFACES_LEVELS_LEVELTWO_H
#define INTERFACES_LEVELS_LEVELTWO_H

class LevelTwo : public LevelInterface {
  public:
  	LevelTwo();
  	UnplacedBlock getNextBlock();
};

#endif