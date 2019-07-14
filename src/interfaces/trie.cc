#include <map>
#include <string>
#include <memory>
#include <utility>
#include "src/interfaces/trie.h"
#include "src/interfaces/trieNode.h"

using namespace std;

Trie::Trie() : root{make_shared<TrieNode>("", false)} {}

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

// Insert unable to insert a new function for the same string :-).
void Trie::insert(string s, CMD c) {

    shared_ptr<TrieNode> tempNode = root;

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

Trie::~Trie() {}