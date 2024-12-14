#ifndef PARSER_H
#define PARSER_H

#include <queue>
#include "Tree.h"

class Parser {
private:
    std::queue<Token>* q; // Queue of tokens for parsing

public:
    // Constructs a parser with a token queue
    explicit Parser(std::queue<Token>* q);

    // Parses a program and returns the root node of its syntax tree
    Node* program();

    // Parses a sequence of statements
    Node* stmt_seq();

    // Parses a single statement
    Node* statement();

    // Parses an if statement
    Node* if_stmt();

    // Parses a repeat statement
    Node* repeat_stmt();

    // Parses an assignment statement
    Node* assign_stmt();

    // Parses a read statement
    Node* read_stmt();

    // Parses a write statement
    Node* write_stmt();

    // Parses an expression
    Node* exp();

    // Parses a simple expression
    Node* simple_exp();

    // Parses a term
    Node* term();

    // Parses a factor
    Node* factor();
};

#endif
