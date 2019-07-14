#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include <memory>
#include <string>
#include "src/interfaces/trie.h"

// Make UI & CMD line into observers to listen for errors
class CommandInterpreter {
    std::unique_ptr<Trie> trie;
    void addCommandsToTrie();
  public:
    CommandInterpreter();
    enum CMD processCommand(std::string cmd);
    // void modifyCommand(std::string original, std::string replacement);
    ~CommandInterpreter();
};

#endif