#ifndef INPUT_PROCESSOR_H
#define INPUT_PROCESSOR_H

#include <memory>
#include <string>
#include "subject.h"

class Trie;

// Must make the UI and CMD line interface adhere to Observer so that InputProcessor may 
// propogate error messages
class InputProcessor: public Subject {
    std::unique_ptr<Trie> trie;
  public:
    InputProcessor();

    // Returns a valid command, other notifies error
    std::string processCommand(std::string cmd);
    void propogateError();

    void modifyCommand(std::string original, std::string replacement);

    ~InputProcessor();
};

#endif