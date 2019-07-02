#ifndef WRAPPER_H
#define WRAPPER_H

#include <memory>
#include <string>
#include "inputProcessor.h"
#include "quadris.h"

class Wrapper {
    std::unique_ptr<InputProcessor> inputProcessor;
    std::unique_ptr<Quadris> quadris;

  public:
    // Run command through processor and if valid, send to quadris.
    void tryCommand(std::string cmd);
};

#endif