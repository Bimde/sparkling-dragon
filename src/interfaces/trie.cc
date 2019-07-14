#include <map>
#include <string>
#include <memory>
#include <utility>
#include <iostream>
#include "src/interfaces/trie.h"

using namespace std;

CMD Trie::search(string s) {
    // unique_ptr<TrieNode> tempNode = make_unique<TrieNode>(root);
    TrieNode * tempNode = root;
    for(int i = 0; i < s.length(); i++) {
        if (tempNode->children.find(s.at(i)) != tempNode->children.end()) {
            // tempNode = make_unique<TrieNode>(tempNode->children.at(s.at(i)));
            tempNode = tempNode->children.at(s.at(i));
            if (s.length()-1 == i) {
                return tempNode->command;   
            }
        } else {
            return CMD::InvalidCommand;
        }
    }
    return CMD::InvalidCommand;
}

// Insert unable to insert a new function for the same string :-).
void Trie::insert(string s, CMD c) {
    if(search(s) == InvalidCommand) return;

    TrieNode * tempNode = root;

    for(int i = 0; i < s.length(); i++) {
        if(tempNode->children.find(s.at(i)) == tempNode->children.end()) {
            for (int j = i; j < s.length(); j++) {
                tempNode->children.insert(pair<char,TrieNode *>(s.at(j), new TrieNode(s.substr(0,j+1), true, c)));
                tempNode = tempNode->children.at(s.at(j));
            }
            return;
        } else {
            tempNode->children.at(s.at(i))->isCommand = false;
            tempNode->children.at(s.at(i))->command = CMD::InvalidCommand;
        }
        tempNode = tempNode->children.at(s.at(i));
    }   
}

Trie::~Trie() {
    delete root;
}