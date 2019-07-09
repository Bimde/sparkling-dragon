#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <memory>
#include <string>
#include "../ui/subject.h"

class Trie;

// Make UI & CMD line into observers to listen for errors
class CommandInterpreter {
    std::unique_ptr<Trie> trie;
  public:
    CommandInterpreter();
    enum CMD processCommand(std::string cmd);
    void modifyCommand(std::string original, std::string replacement);
    ~CommandInterpreter();
};

#endif