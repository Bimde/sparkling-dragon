#include "src/interfaces/commandInterpreter.h"
#include "src/interfaces/commands.h"
#include <iostream>

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
    trie->insert("autodown", CMD::AutoDown);
    trie->insert("stopautodown", CMD::StopAutoDown);
    trie->insert("i", CMD::SpawnIBlock);
    trie->insert("j", CMD::SpawnJBlock);
    trie->insert("l", CMD::SpawnLBlock);
    trie->insert("o", CMD::SpawnOBlock);
    trie->insert("s", CMD::SpawnSBlock);
    trie->insert("z", CMD::SpawnZBlock);
    trie->insert("t", CMD::SpawnTBlock);
    trie->insert("sequence", CMD::UseSequenceFile);
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