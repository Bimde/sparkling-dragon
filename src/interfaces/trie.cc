#include <map>
#include <string>
#include <memory>
#include <utility>
#include <iostream>
#include "trie.h"

using namespace std;

// Node Classes

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

// Insert unable to insert a new function for the same string :-) kek.
void Trie::insert(string s, CMD c) {
    if(search(s) == c) return;

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

// int main() {
//     Trie t;
//     t.insert("left", CMD::Left);
//     t.insert("right", CMD::Right);
//     t.insert("down", CMD::Down);
//     t.insert("counterclockwise", CMD::RotateLeft);
//     t.insert("clockwise", CMD::RotateRight);
//     t.insert("drop", CMD::Drop);
//     t.insert("levelup", CMD::LevelUp);
//     t.insert("leveldown", CMD::LevelDown);
//     t.insert("norandom", CMD::NoRandom);
//     t.insert("random", CMD::Random);
//     t.insert("restart", CMD::Restart);
//     t.insert("hint", CMD::Hint);
//     // t.insert("removehint", CMD::RemoveHint);
//     // t.insert("invalidcommand", CMD::InvalidCommand);
//     // t.insert("aftermoveturn", CMD::AfterMoveTurn);

//     cout << t.search("leveld") << endl;
//     cout << t.search("r") << endl;
//     cout << t.search("hin") << endl;
//     cout << t.search("hints") << endl;

//     cout << t.search("leveld") << endl;

//     return 0;
// }