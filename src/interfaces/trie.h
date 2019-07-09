#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <string>
#include <memory>
#include "quadris.h"


class Trie {
    class Node {
      public:
        std::string curStr;
        bool isCommand;
        enum CMD command;
        std::map<char, std::unique_ptr<Node>> children;
        
        Node(std::string str, bool isCommand, CMD command = CMD::InvalidCommand): curStr{str}, isCommand{isCommand}, command{command} {};
    };
    std::unique_ptr<Node> root;
  public:
    Trie(): root{std::make_unique<Node>("", false)} {}

    std::string search(std::string);
    void insert(std::string, CMD);
    void update(std::string, std::string);
    void remove(std::string);

    ~Trie();
};

#endif