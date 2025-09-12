#include<bits/stdc++.h >
using namespace std;
int main(){
    stack<int> s;
    char exp[100];
    cout<<"Enter a prefix expression: ";
    cin>>exp;
    int l=strlen(exp);
    for(int i=l-1;i>=0;i--){
        if(isdigit(exp[i])){
            s.push(exp[i]-'0');
        }
        else{
            int x=s.top();
            s.pop();
            int y=s.top();
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
    cout<<"Result: "<<s.top()<<endl;
    return 0;
}
