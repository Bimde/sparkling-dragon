#include <iostream>
#include "commandInterpreter.h"

using namespace std;

void CommandInterpreter::addCommandsToTrie() {
    trie->insert("left", CMD::Left);
    trie->insert("right", CMD::Right);
    trie->insert("down", CMD::Down);
    trie->insert("counterclockwise", CMD::RotateLeft);
    trie->insert("clockwise", CMD::RotateRight);
    trie->insert("drop", CMD::Drop);
    trie->insert("levelup", CMD::LevelUp);
    trie->insert("leveldown", CMD::LevelDown);
    trie->insert("norandom", CMD::NoRandom);
    trie->insert("random", CMD::Random);
    trie->insert("restart", CMD::Restart);
    trie->insert("hint", CMD::Hint);
    // t.insert("removehint", CMD::RemoveHint);
    // t.insert("invalidcommand", CMD::InvalidCommand);
    // t.insert("aftermoveturn", CMD::AfterMoveTurn);
}

CommandInterpreter::CommandInterpreter(): trie{make_unique<Trie>()} {
    addCommandsToTrie();
}

enum CMD CommandInterpreter::processCommand(string cmd) {
    return trie->search(cmd);
}

CommandInterpreter::~CommandInterpreter() {}

// int main() {
//     CommandInterpreter ci;
//     cout << ci.processCommand("rand") << endl;
//     cout << ci.processCommand("hint") << endl;
//     cout << ci.processCommand("r") << endl;
//     return 0;
// }