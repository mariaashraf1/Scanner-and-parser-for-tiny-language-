#include "Tree.h"

Node::Node() : siblingNodes(nullptr) {}

Node::Node(const Token& key) : key(key), siblingNodes(nullptr) {}

Node* Node::newNode(const Token& key) {
    return new Node(key);
}

std::vector<Node*> Node::getChildren() const {
    return children;
}

void Node::setChildren(const std::vector<Node*>& newChildren) {
    children = newChildren;
}

void Node::addChild(Node* child) {
    children.push_back(child);
}
