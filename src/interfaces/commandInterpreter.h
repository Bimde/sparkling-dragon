#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <memory>
#include <string>
#include "subject.h"

class Trie;

// Make UI & CMD line into observers to listen for errors
class CommandInterpreter: public Subject {
    std::unique_ptr<Trie> trie;
  public:
    CommandInterpreter();
    std::string processCommand(std::string cmd);
    void modifyCommand(std::string original, std::string replacement);

    ~CommandInterpreter();
};

#endif