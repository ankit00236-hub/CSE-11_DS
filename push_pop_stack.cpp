#include<iostream>
using namespace std;
struct stack{
    int top;
    int arr[100];
};
void push(stack &s, int x){
    if(s.top==99){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    s.arr[++s.top]=x;
}
int pop(stack &s){
    if(s.top==-1){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    return s.arr[s.top--];
}
int IsEmpty(stack &s){
    if(s.top==-1){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return s.arr[s.top];
}
bool isEmpty(stack &s){
    return s.top==-1;
}
int main(){
    stack s;
    s.top=-1;
    push(s,11);
    push(s,22);
    push(s,33);
    cout<<"Top element is: "<<IsEmpty(s)<<endl;
    cout<<"Popped element is: "<<pop(s)<<endl;
    cout<<"Top element is: "<<IsEmpty(s)<<endl;
    cout<<"Is stack empty? "<<(isEmpty(s)?"Yes":"No")<<endl;
    pop(s);
    pop(s);
    cout<<"Is stack empty? "<<(isEmpty(s)?"Yes":"No")<<endl;
    return 0;
}
   