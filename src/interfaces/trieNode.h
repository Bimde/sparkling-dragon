#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <string>
#include <memory>
#include <map>
#include "src/interfaces/commands.h"

class TrieNode {
    void swap(TrieNode &other);
  public:
    std::string curStr;
    bool isCommand;
    enum CMD command;
    
    // TODO: Make children TireNodes unique_ptr's
    std::map<char, std::shared_ptr<TrieNode> > children;
    
    TrieNode(std::string, bool, enum CMD = CMD::InvalidCommand);
    TrieNode(const TrieNode &);
    TrieNode(TrieNode &&);
    TrieNode& operator=(const TrieNode &);
    TrieNode& operator=(TrieNode &&);
    ~TrieNode();
};

#endif