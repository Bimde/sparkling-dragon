#ifndef TRIE_H
#define TRIE_H

#include <map>
#include <string>
#include <memory>
#include "trieNode.h"
// #include "quadris.h"

// TODO Remove this after importing quadris.h
// enum CMD{ 
// 			Left, Right, Down, RotateLeft, RotateRight, Drop, 
// 		  	LevelUp, LevelDown, NoRandom, Random, Restart, 
// 		  	Hint, RemoveHint, InvalidCommand, AfterMoveTurn
// 		};

class Trie {
    TrieNode *root;
  public:
    Trie(): root{new TrieNode("", false)} {}
    CMD search(std::string);
    void insert(std::string, CMD);
    // void update(std::string, std::string);
    // void remove(std::string);

    // ~Trie();
};

#endif