#include <map>
#include <string>
#include <memory>
#include <utility>
#include "src/interfaces/trie.h"
#include "src/interfaces/trieNode.h"

using namespace std;

Trie::Trie() : root{make_shared<TrieNode>("", false, false)} {}

CMD Trie::search(string s) {
    shared_ptr<TrieNode> tempNode = root;
    for(int i = 0; i < s.length(); i++) {
        if (tempNode->children.find(s.at(i)) != tempNode->children.end()) {
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

// Precondition: string s is not already in Trie
void Trie::insert(string s, CMD c) {

    shared_ptr<TrieNode> tempNode = root;

    for(int i = 0; i < s.length(); i++) {
        // If next character is not in children
        if (tempNode->children.find(s.at(i)) == tempNode->children.end()) {
            for (int j = i; j < s.length(); j++) {
                tempNode->children.emplace(s.at(j), make_shared<TrieNode>(s.substr(0,j+1), true, false, c));
                tempNode = tempNode->children.at(s.at(j));
                if (j == s.length()-1) {
                    tempNode->isFullCommand = true;
                }
            }
            return;
        // If character is in children
        } else {
            tempNode = tempNode->children.at(s.at(i));
            if (!tempNode->isFullCommand) {
                tempNode->isCommand = false;
                tempNode->command = CMD::InvalidCommand;
            }

            if (i == s.length()-1) {
                tempNode->isCommand = true;
                tempNode->isFullCommand = true;
                tempNode->command = c;
            }
        }
    }   
}

Trie::~Trie() {}