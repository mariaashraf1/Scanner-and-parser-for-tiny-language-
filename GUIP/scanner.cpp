#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <map>
#include <queue>





using namespace std;

string scanner(const string& input) {
    map<string, string> tokenTypes = {
        {";", "SEMICOLON"},
        {"if", "IF"},
        {"then", "THEN"},
        {"end", "END"},
        {"repeat", "REPEAT"},
        {"until", "UNTIL"},
        {":=", "ASSIGN"},
        {"read", "READ"},
        {"write", "WRITE"},
        {"<", "LESSTHAN"},
        {"=", "EQUAL"},
        {"+", "PLUS"},
        {"-", "MINUS"},
        {"*", "MULT"},
        {"/", "DIV"},
        {"(", "OPENBRACKET"},
        {")", "CLOSEDBRACKET"}
    };

    ostringstream result;
    string currentToken;
    size_t i = 0;
    bool insideComment = false;

    while (i < input.size()) {
        char c = static_cast<unsigned char>(input[i]); // Ensure valid range

        // Handle comments: Ignore anything inside {}
        if (c == '{') {
            insideComment = true;
            ++i;
            continue;
        }
        if (c == '}' && insideComment) {
            insideComment = false;
            ++i;
            continue;
        }
        if (insideComment) {
            ++i;
            continue; // Skip characters inside comments
        }

        if (isspace(c)) {
            // Skip whitespace
            ++i;
            continue;
        }

        currentToken.clear();

        if (isalpha(c)) {
            // Process identifiers and keywords
            while (i < input.size() && (isalnum(static_cast<unsigned char>(input[i])) || input[i] == '_')) {
                currentToken += input[i];
                ++i;
            }
            if (tokenTypes.find(currentToken) != tokenTypes.end()) {
                result << currentToken << "," << tokenTypes[currentToken] << "\n";
            }
            else {
                result << currentToken << ",IDENTIFIER\n";
            }
        }
        else if (isdigit(c)) {
            // Process numbers
            while (i < input.size() && isdigit(static_cast<unsigned char>(input[i]))) {
                currentToken += input[i];
                ++i;
            }
            result << currentToken << ",NUMBER\n";
        }
        else {
            // Process special characters and operators
            currentToken += c;
            if (c == ':' && i + 1 < input.size() && input[i + 1] == '=') {
                currentToken += input[++i]; // Append '=' for ":="
            }
            ++i;
            if (tokenTypes.find(currentToken) != tokenTypes.end()) {
                result << currentToken << "," << tokenTypes[currentToken] << "\n";
            }
            else {
                result << currentToken << ",UNKNOWN\n";
            }
        }
    }

    return result.str();
}



string newLinesinString(string input) {
    string result;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == '\n') {
            result += "\r\n";

        }
        else {
            result += input[i];
        }
    }
    return result;
}