#include "trieNode.h"
#include <string>
#include <memory>
#include <map>

using namespace std;

void TrieNode::swap(TrieNode &other) {
    using std::swap;
    swap(curStr, other.curStr);
    swap(isCommand, other.isCommand);
    swap(command, other.command);
    swap(children, other.children);
}


TrieNode::TrieNode(string str, bool isCommand, enum CMD command): curStr{str}, isCommand{isCommand}, command{command} {}
TrieNode::TrieNode(const TrieNode & o): curStr{o.curStr}, isCommand{o.isCommand}, command{o.command}, children{o.children} {}
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