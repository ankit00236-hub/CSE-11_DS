#include<bits/stdc++.h >
using namespace std;
int main(){
    stack<int> s;
    char exp[100];
    cout<<"Enter a postfix expression: ";
    cin>>exp;
    for(int i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i])){
            s.push(exp[i]-'0');
        }
        else{
            int y=s.top();
            s.pop();
            int x=s.top();
            s.pop();
            switch(exp[i]){
                case '+':s.push(x+y);break;
                case '*':s.push(x*y);break;
                case '/':s.push(x/y);break;
                case '^':s.push(pow(x,y));break;
                case '-':s.push(x-y);break;
            }
        }

    }
    
    cout<<"Result of postfix: "<<s.top()<<endl;

    
    
    return 0;
}