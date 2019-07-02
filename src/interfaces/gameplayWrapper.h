#ifndef GAMEPLAY_WRAPPER_H
#define GAMEPLAY_WRAPPER_H

#include <memory>
#include <string>
#include "commandInterpreter.h"
#include "quadris.h"

class GameplayWrapper {
    std::unique_ptr<CommandInterpreter> commandInterpreter;
    std::unique_ptr<Quadris> quadris; 
  public:
    GameplayWrapper(CommandInterpreter * ci, Quadris * q);
    void tryCommand(std::string cmd);
};

#endif