#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}