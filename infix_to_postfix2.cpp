#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
using namespace std;
struct stk{
    int temp[100];
    int top;
};
struct stk s;
void initialisation(){
    s.top=-1;
}
bool IsEmpty(){
    if (s.top==-1){
        return true;
    }
    else{
        return false;
    }
}
void push(int x){
    if (s.top==99){
        cout<<"stack overflow";
        exit(1);
    }
    else{
        s.top=s.top+1;
        s.temp[s.top]=x;
    }
}
char pop(){
    if (IsEmpty()){
        cout<<"STACK UNDERFLOW";
        exit(1);
    }
    else{
        char x=s.temp[s.top];
        s.top=s.top-1;
        return x;
    }
}
char stacktop(){
    return s.temp[s.top];
}

    



bool prcd(char s1,char s2){
    if(s1=='('||s2=='('){
        return false;
    }
    else if(s2==')'){
        return true;
    }
    else if(s1=='^'||s1=='*'||s1=='/'||s1=='%'){
        if(s2=='^'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(s1=='+'||s1=='-'){
        if(s2=='+'||s2=='-'){
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    initialisation();
    int i=0;
    char infix[30];
    cin>>infix;
    vector<char>postfix;
    while(infix[i]!='\0'){
        char symb=infix[i];
        i++;
        if(symb>='a' && symb<='z'){
            postfix.push_back(symb);
        }
        else{
            while(!IsEmpty() && prcd(stacktop(),symb)){
                char x=pop();
                postfix.push_back(x);
            }
            if(symb!=')'){
                push(symb);
            }
            else{
                pop();
            }
        }
    }
    while(!IsEmpty()){
        char x=pop();
        postfix.push_back(x);
    }
    for(char c:postfix){
        cout<<c;
    }
    
    return 0;
}