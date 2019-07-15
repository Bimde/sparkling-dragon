#include <string>
#include <memory>
#include <map>
#include "src/interfaces/trieNode.h"
#include "src/interfaces/commands.h"

using namespace std;

void TrieNode::swap(TrieNode &other) {
    using std::swap;
    swap(curStr, other.curStr);
    swap(isCommand, other.isCommand);
    swap(command, other.command);
    swap(children, other.children);
}

TrieNode::TrieNode(string str, bool isCommand, bool isFullCommand, enum CMD command): curStr{str}, isCommand{isCommand}, isFullCommand{isFullCommand}, command{command} {}
TrieNode::TrieNode(const TrieNode & o): curStr{o.curStr}, isCommand{o.isCommand}, isFullCommand{o.isFullCommand}, command{o.command}, children{o.children} {}
TrieNode::TrieNode(TrieNode && o): curStr{std::move(o.curStr)}, isCommand{std::move(o.isCommand)}, command{std::move(o.command)}, children{std::move(o.children)} {}

TrieNode& TrieNode::operator=(const TrieNode & o) {
    TrieNode temp{o};
    swap(temp);
    return *this;
}

TrieNode& TrieNode::operator=(TrieNode && o) {
    swap(o);
    return *this;
}

TrieNode::~TrieNode() {}