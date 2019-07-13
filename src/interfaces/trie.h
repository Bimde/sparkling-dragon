#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <string>
#include <memory>
#include "trieNode.h"
#include "commands.h"

class Trie {
    TrieNode *root;
  public:
    Trie(): root{new TrieNode("", false)} {}
    CMD search(std::string);
    void insert(std::string, CMD);
    // void update(std::string, std::string);
    // void remove(std::string);

    ~Trie();
};

#endif