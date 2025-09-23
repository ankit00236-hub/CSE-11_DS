#include <iostream>
#include <stack>
#include <string>
#include <algorithm> 
#include <cctype>    

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}


string infixToPostfix(const string &infix) {
    stack<char> s;
    string postfix;
    for (char c : infix) {
        if (isalnum(c)) postfix += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top(); s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else if (isOperator(c)) {
            while (!s.empty() &&
                   ((precedence(s.top()) > precedence(c)) ||
                    (precedence(s.top()) == precedence(c) && c != '^'))) {
                postfix += s.top(); s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) { postfix += s.top(); s.pop(); }
    return postfix;
}


string infixToPostfixForReversed(const string &infix) {
    stack<char> s;
    string postfix;
    for (char c : infix) {
        if (isalnum(c)) postfix += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top(); s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else if (isOperator(c)) {
            while (!s.empty() &&
                   ((precedence(s.top()) > precedence(c)) ||
                    (precedence(s.top()) == precedence(c) && c == '^'))) {
                postfix += s.top(); s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) { postfix += s.top(); s.pop(); }
    return postfix;
}

string infixToPrefix(string infix) {
    // Reverse & swap brackets
    reverse(infix.begin(), infix.end());
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    // Convert modified (reversed) infix to postfix using special rules
    string postfix = infixToPostfixForReversed(infix);
    // Reverse postfix -> prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix  = infixToPrefix(infix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Prefix expression:  " << prefix << endl;
    return 0;
}