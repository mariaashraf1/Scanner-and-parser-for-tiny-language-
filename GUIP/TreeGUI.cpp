#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include "parse.h"
#include <cstdio> // For remove()

using namespace std;

Parser::Parser(std::queue<Token>* q) : q(q) {
    // Constructor body
}
Node* Parser::program() {

    Token error{ "missing ;","ERROR" };

    // Call stmt_seq() to get the statement sequence
    Node* root = stmt_seq();

    // Check if stmt_seq() returned an error node
    if (root->key.type == "ERROR") {
        return root;  // Return the error node directly
    }
    // If there are remaining tokens and no more statements are valid, create an error node
    else if (!q->empty()) {
        root = Node::newNode(error);
    }

    return root;
}

Node* Parser::stmt_seq() {
    Node* temp = statement();
    Node* root = temp;

    if (temp->key.type != "ERROR") {
        while (!q->empty() && q->front().type == "SEMICOLON") {
            q->pop();
            Node* sibling = statement();
            if (sibling->key.type == "ERROR") {
                root = sibling;
                break;
            }
            else {
                temp->siblingNodes = sibling;
                temp = temp->siblingNodes;
            }
        }
    }

    return root;
}

Node* Parser::statement() {
    Node* root = nullptr;
    Token error{ "invalid statement","ERROR" };

    if (!q->empty()) {
        std::string type = q->front().type;
        if (type == "IF") {
            root = if_stmt();
        }
        else if (type == "REPEAT") {
            root = repeat_stmt();
        }
        else if (type == "IDENTIFIER") {
            root = assign_stmt();
        }
        else if (type == "READ") {
            root = read_stmt();
        }
        else if (type == "WRITE") {
            root = write_stmt();
        }
        else {
            root = Node::newNode(error);
        }
    }
    else {
        root = Node::newNode(error);
    }

    return root;
}

Node* Parser::if_stmt() {
    Node* root = nullptr;
    Node* child;
    Token error{ "syntax error in if-statement","ERROR" };

    if (q->front().type == "IF") {
        root = Node::newNode(q->front());
        q->pop();
        child = exp();
        if (child->key.type == "ERROR") {
            root = child;
        }
        else {
            root->children.push_back(child);
            if (!q->empty() && q->front().type == "THEN") {
                q->pop();
                child = stmt_seq();
                if (child->key.type == "ERROR") {
                    root = child;
                }
                else {
                    root->children.push_back(child);
                    if (!q->empty() && q->front().type == "ELSE") {
                        q->pop();
                        child = stmt_seq();
                        if (child->key.type == "ERROR") {
                            root = child;
                        }
                        else {
                            root->children.push_back(child);
                        }
                    }
                    if (!q->empty() && q->front().type == "END") {
                        q->pop();
                    }
                    else {
                        root = Node::newNode(error);
                    }
                }
            }
            else {
                root = Node::newNode(error);
            }
        }
    }

    return root;
}

Node* Parser::repeat_stmt() {
    Node* root = nullptr;
    Node* child;
    Token error{ "missing until in repeat-statement", "ERROR" };

    if (q->front().type == "REPEAT") {
        root = Node::newNode(q->front());
        q->pop();
        child = stmt_seq();
        if (child->key.type == "ERROR") {
            root = child;
        }
        else {
            root->children.push_back(child);
            if (!q->empty() && q->front().type == "UNTIL") {
                q->pop();
                child = exp();
                if (child->key.type == "ERROR") {
                    root = child;
                }
                else {
                    root->children.push_back(child);
                }
            }
            else {
                root = Node::newNode(error);
            }
        }
    }

    return root;
}

Node* Parser::assign_stmt() {
    Node* root = nullptr;
    Node* child;
    Token assign;
    Token error{ "missing until in repeat-statement", "ERROR" };

    if (q->front().type == "IDENTIFIER") {
        assign.value = q->front().value;
        q->pop();
        if (!q->empty() && q->front().type == "ASSIGN") {
            assign.type = "ASSIGN";
            q->pop();
            root = Node::newNode(assign);
            child = exp();
            if (child->key.type == "ERROR") {
                root = child;
            }
            else {
                root->children.push_back(child);
            }
        }
        else {
            root = Node::newNode(error);
        }
    }

    return root;
}

Node* Parser::read_stmt() {
    Node* root = nullptr;
    Token r;
    Token error{ "invalid read syntax","ERROR" };

    if (q->front().type == "READ") {
        r.type = "READ";
        q->pop();
        if (!q->empty() && q->front().type == "IDENTIFIER") {
            r.value = q->front().value;
            q->pop();
            root = Node::newNode(r);
        }
        else {
            root = Node::newNode(error);
        }
    }

    return root;
}

Node* Parser::write_stmt() {
    Node* root = nullptr;
    Node* child;
    Token error{ "invalid write syntax", "ERROR" };

    if (q->front().type == "WRITE") {
        root = Node::newNode(q->front());
        q->pop();
        child = exp();
        if (child->key.type == "ERROR") {
            root = child;
        }
        else {
            root->children.push_back(child);
        }
    }
    else {
        root = Node::newNode(error);
    }

    return root;
}

Node* Parser::exp() {
    Node* simple_1 = simple_exp();
    Node* op = simple_1;

    if (simple_1->key.type != "ERROR") {
        if (!q->empty() && (q->front().value == "<" || q->front().value == "=")) {
            Token comparison_op{ "OP", q->front().value };
            op = Node::newNode(comparison_op);
            q->pop();
            Node* simple_2 = simple_exp();
            op->children.push_back(simple_1);
            if (simple_2->key.type == "ERROR") {
                op = simple_2;
            }
            else {
                op->children.push_back(simple_2);
            }
        }
    }

    return op;
}

Node* Parser::simple_exp() {
    Node* term_1 = term();

    if (term_1->key.type != "ERROR") {
        while (!q->empty() && (q->front().value == "+" || q->front().value == "-")) {
            Token add_op{ "OP", q->front().value };
            Node* add_op_node = Node::newNode(add_op);
            q->pop();
            Node* term_2 = term();
            add_op_node->children.push_back(term_1);
            if (term_2->key.type == "ERROR") {
                term_1 = term_2;
                break;
            }
            else {
                add_op_node->children.push_back(term_2);
                term_1 = add_op_node;
            }
        }
    }

    return term_1;
}

Node* Parser::term() {
    Node* root = factor();

    if (root->key.type != "ERROR") {
        while (!q->empty() && (q->front().type == "MULT" || q->front().type == "DIV")) {
            Node* left = root;
            Token op{ "OP", q->front().value };
            root = Node::newNode(op);
            root->children.push_back(left);
            q->pop();
            Node* right = factor();
            if (right->key.type == "ERROR") {
                root = right;
                break;
            }
            else {
                root->children.push_back(right);
            }
        }
    }

    return root;
}

Node* Parser::factor() {
    Token error{ "invalid syntax", "ERROR" };

    if (!q->empty()) {
        std::string t = q->front().type;
        if (t == "OPENBRACKET") {
            q->pop();
            Node* root = exp();
            if (!q->empty() && q->front().type == "CLOSEDBRACKET") {
                q->pop();
            }
            else {
                error.value = "missing closed brackets";
                root = Node::newNode(error);
            }
            return root;
        }
        else if (t == "NUMBER") {
            Token temp{ "Const", q->front().value };
            Node* root = Node::newNode(temp);
            q->pop();
            return root;
        }
        else if (t == "IDENTIFIER") {
            Node* root = Node::newNode(q->front());
            q->pop();
            return root;
        }
    }

    error.value = "incomplete expression.";
    return Node::newNode(error);
}



// Syntax Tree Drawer class
class SyntaxTree {
private:
    int counter;

    int drawNode(Node* node, std::string& str, int id) {
        int edge;

        // Generate the node style based on its type
        if (node->key.type == "READ" || node->key.type == "ASSIGN") {
            str += "node[shape = rect label=\"" + node->key.type + "\\n(" + node->key.value + ")\"]id" + std::to_string(id) + " ";
        }
        else if (node->key.type == "IF" || node->key.type == "WRITE" || node->key.type == "REPEAT") {
            str += "node[shape = rect label=\"" + node->key.type + "\"]id" + std::to_string(id) + " ";
        }
        else if (node->key.value == "OP" || node->key.value == "Const") {
            str += "id" + std::to_string(id) + " [shape=oval, label=\"" + node->key.value + "\\n(" + node->key.type + ")\"];\n";
        }
        else {
            str += "node[shape = oval label=\"" + node->key.type + "\\n(" + node->key.value + ")\"]id" + std::to_string(id) + " ";
        }

        // Traverse child nodes
        for (int i = 0; i < (int)node->children.size(); i++) {
            counter++;
            edge = drawNode(node->children[i], str, counter);
            str += "id" + std::to_string(id) + "--id" + std::to_string(edge) + " ";
            node->children[i]->key.id = edge;
        }

        // Handle the "IF" type node for special sibling ranking
        if (node->key.type == "IF") {
            Node* temp;
            Node* temp2;
            for (int i = 0; i < (int)node->children.size() - 1; i++) {
                if (node->children[i]->siblingNodes != nullptr) {
                    temp = node->children[i]->siblingNodes;
                    temp2 = node->children[i + 1];
                    str += "{rank = same; id" + std::to_string(temp->key.id) + "; id" + std::to_string(temp2->key.id) + "; }";
                    str += " id" + std::to_string(temp->key.id) + "--id" + std::to_string(temp2->key.id) + " [style = invis]; ";
                }
            }
        }

        for (int i = 0; i < (int)node->children.size() - 1; i++) {
            Node* temp;
            Node* temp2;
            if (node->children.size() > 1 && node->siblingNodes == nullptr) {
                temp = node->children[i];
                temp2 = node->children[i + 1];
                str += "{rank = same; id" + std::to_string(temp->key.id) + "; id" + std::to_string(temp2->key.id) + "; }";
                str += " id" + std::to_string(temp->key.id) + "--id" + std::to_string(temp2->key.id) + " [style = invis]; ";
            }
        }

        // Traverse sibling nodes
        if (node->siblingNodes != nullptr) {
            counter++;
            edge = drawNode(node->siblingNodes, str, counter);
            str += "{rank = same; id" + std::to_string(id) + "; id" + std::to_string(edge) + "; }";
            str += " id" + std::to_string(id) + "--id" + std::to_string(edge) + " ";
            node->siblingNodes->key.id = edge;
        }

        return id;
    }

public:
    SyntaxTree() : counter(1) {}

    void draw(Node* tree) {
        string dotText = "graph syntaxTree {\n";
        dotText += "node [fontname=\"Arial\"];\n"; // Styling for better visibility
        drawNode(tree, dotText, 1);
        dotText += "}\n";

        // Write DOT content to a file
        ofstream file("tree1.dot");
        if (!file.is_open()) {
            cerr << "Error: Could not create file.\n";
            return;
        }
        file << dotText;
        file.close();

        // Generate the PNG
        string command = "dot -Tpng tree1.dot -o tree1.png";
        system(command.c_str());
    }
};


// Function to read tokens from a file and return a queue of tokens
queue<Token> readTokensFromFile(const string& fileText) {
    std::queue<Token> tokens;
    std::istringstream stream(fileText); // Use string stream to simulate reading from a file
    std::string line;

    // Process each line in the input text
    while (std::getline(stream, line)) {
        std::istringstream ss(line); // Process individual line as a stream
        std::string value, type;

        // Split the line into 'value' and 'type' using ',' as a delimiter
        if (std::getline(ss, value, ',') && std::getline(ss, type, ',')) {
            // Remove leading and trailing spaces using regex
            value = std::regex_replace(value, std::regex("^ +| +$|( ) +"), "$1");
            type = std::regex_replace(type, std::regex("^ +| +$|( ) +"), "$1");

            // Add the token to the queue
            tokens.push({ value, type });
        }
    }

    return tokens;
}


// Helper function to recursively check for errors in the parse tree
bool containsError(Node* node) {
    if (!node) return false;

    // Check if the current node contains an error
    if (node->key.type == "ERROR") {
        return true;
    }

    //Check all children nodes
    for (Node* child : node->children) {
        if (containsError(child)) {
            return true;
        }
    }
    

    // Check sibling nodes
    if (containsError(node->siblingNodes)) {
        return true;
    }

    return false;
}

/*Main function
int main() {
    string tokenFilename = "tokens-2.txt"; // Replace with your token file

    queue<Token> tokens = readTokensFromFile(tokenFilename);
    Parser parser(&tokens);
    Node* parseTree = parser.program();

    cout << "Parse Tree generated successfully.\n";

    // Draw the syntax tree
    SyntaxTree treeDrawer;
    treeDrawer.draw(parseTree);

    cout << "Syntax tree has been generated as 'tree.png'.\n";
    return 0;
} */