#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int main(){
    stack<char> s;
    string infix, postfix;
    cout<<"Enter an infix expression: ";
    cin>>infix;
    for(int i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            postfix+=infix[i];
        }
        else if(infix[i]=='('){
            s.push(infix[i]);
        }
        else if(infix[i]==')'){
            while(!s.empty() && s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            s.pop(); 
        }
        else if(isOperator(infix[i])){
            while(!s.empty() && precedence(s.top())>=precedence(infix[i])){
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    cout<<"Postfix expression: "<<postfix<<endl;
    return 0;
}