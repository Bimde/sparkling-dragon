#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <memory>
#include <string>
#include "src/interfaces/trie.h"

class CommandInterpreter {
    std::unique_ptr<Trie> trie;
    void addCommandsToTrie();
  public:
    CommandInterpreter();
    enum CMD processCommand(std::string cmd);
    ~CommandInterpreter();
};

#endif