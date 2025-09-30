#include<bits/stdc++.h>
using namespace std;
struct node
{
    char info;
    struct node* next;
    struct node* prev;
};
struct node* start;
node* getnode(char x){
    struct node* p;
    p = new node();
    p->info = x;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void insert_beg(char x){
    struct node* p;
    p = getnode(x);
    if(start==NULL){
        start = p;
    }
    else{
        p->next = start;
        start->prev = p;
        start = p;
    }
}

void traverse(){
    struct node* p;
    p = start;
    while(p!=NULL){
        cout<<p->info<<" ";
        p = p->next;
    }
    cout<<endl;

}
void insert_end(char x){
    struct node* p, *q;
    p = getnode(x);
    if(start==NULL){
        start = p;
    }
    else{
        q = start;
        while(q->next!=NULL){
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }
}
// ********************************************
int count_nodes(){
    struct node* p;
    int c = 0;
    p = start;
    while(p!=NULL){
        c++;
        p = p->next;
    }
    return c;
}


int main(){
    start = NULL;
    insert_beg('A');
    insert_beg('B');
    insert_beg('C');
    traverse();
    insert_end('D');
    traverse();
    cout<<count_nodes()<<endl;
    
    
    return 0;
}