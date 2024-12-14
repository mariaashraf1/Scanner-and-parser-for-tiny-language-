#ifndef TREE_H
#define TREE_H

#include <vector>
#include <string>

struct Token {
    std::string value;
    std::string type;
    int id;

};

class Node {
public:
    Token key;
    std::vector<Node*> children;
    Node* siblingNodes;

    Node(); // Default constructor
    Node(const Token& key); // Constructor with a Token argument

    static Node* newNode(const Token& key);

    std::vector<Node*> getChildren() const;
    void setChildren(const std::vector<Node*>& newChildren);
    void addChild(Node* child);
};

#endif
