#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <string>
#include <memory>
#include "src/interfaces/trieNode.h"
#include "src/interfaces/commands.h"

class Trie {
    std::shared_ptr<TrieNode> root;
  public:
    Trie();
    CMD search(std::string);
    void insert(std::string, CMD);
    // void update(std::string, std::string);
    // void remove(std::string);

    ~Trie();
};

#endif