#include <map>
#include <string>
#include <memory>
#include "trie.h"

using namespace std;

CMD Trie::search(string s) {
    unique_ptr<Node> tempNode = make_unique<Node>(root);
    for(int i = 0; i < s.length; i++) {
        if (tempNode->children.find(s.at(i)) != tempNode->children.end()) {
            tempNode = make_unique<Node>(tempNode->children.at(s.at(i)));
            if (s.length-1 == i) {
                return tempNode->command;   
            }
        }
    }
    return CMD::InvalidCommand;
}

void Trie::insert(string s, CMD c) {
    if(search(s) == c) return;

    unique_ptr<Node> tempNode = make_unique<Node>(root);
    for(int i = 0; i < s.length; i++) {
        if(tempNode->children.find(s.at(i)) == tempNode->children.end()) {
            tempNode->children[s.at(i)] = make_unique<Node>(s.substr(0,i+1), true, c);
        } else {
            tempNode->children.at(s.at(i))->isCommand = false;
            tempNode->children.at(s.at(i))->isCommand = CMD::InvalidCommand;
        }
        tempNode = make_unique<Node>(tempNode->children.at(s.at(i)));
    }   
}
