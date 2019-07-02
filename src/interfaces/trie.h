#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>
#include <memory>


class Trie {
    class Node {
        std::string curStr;
        char curChar;

        std::vector<std::pair<char, std::string>> children;
    };
    std::unique_ptr<Node> root;
  public:
    Trie();
    Trie(std::vector<std::string>);

    std::string search(std::string);
    void insert(std::string);
    void remove(std::string);

    ~Trie();
};

#endif