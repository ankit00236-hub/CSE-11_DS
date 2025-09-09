#include<bits/stdc++.h >
using namespace std;
stack<int> s;
void dtb(int n)  
{  
    if(n==0)
    {
        return;
    }
    s.push(n%2);
    dtb(n/2);
}
void dtoc(int n)  
{  
    if(n==0)
    {
        return;
    }
    s.push(n%8);
    dtoc(n/8);
}   
void dth(int n)  
{  
    if(n==0)
    {
        return;
    }
    s.push(n%16);
    dth(n/16);
}
void dtn(int n,int b)  
{  
    if(n==0)
    {
        return;
    }
    s.push(n%b);
    dtn(n/b,b);
}
int main()
{
    int n;
    char data[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    cout<<"Enter a decimal number: ";
    cin>>n;
    dtb(n);
    cout<<"Binary representation: ";
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    dtoc(n);
    cout<<"Octal representation: ";
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    dth(n); 
    cout<<"Hexadecimal representation: ";
    while(!s.empty())
    {
        cout<<data[s.top()];
        s.pop();
    }
    cout<<endl;
    cout<<"Enter any other base (2-26): ";
    int b;
    cin>>b;
    if(b<2 || b>26)
    {
        cout<<"Base out of range"<<endl;
        return 0;
    }
    dtn(n,b);
    cout<<"Base "<<b<<" representation: ";
    while(!s.empty())
    {
        cout<<data[s.top()];
        s.pop();
    }
    return 0;
}