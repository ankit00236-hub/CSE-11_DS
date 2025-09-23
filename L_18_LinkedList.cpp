#include<bits/stdc++.h>
using namespace std;
struct node
{
    char info;
    struct node* next;
};

struct node* start;

node* getnode(char x){
    struct node* p;
    p = new node();
    p->info = x;
    p->next = NULL;
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
    }
}

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

int middleelement(){
    struct node* p, *q;
    p = start;
    q = start;
    if(start==NULL){
        return -1;
    }
    else{
        while(q!=NULL && q->next!=NULL){
            p = p->next;
            q = q->next->next;
        }
        cout<< p->info<<endl;
        return 0;
    }
}
int middleelement2(){
    struct node* p;
    int c = count_nodes();
    int mid = c/2;
    p = start;
    for(int i=0;i<mid;i++){
        p = p->next;
    }
    cout<<p->info<<endl;
    return 0;
}
void reverse(){
    struct node* prev, *curr, *next;
    prev = NULL;
    curr = start;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
}
void orderedinsert(char x){
    struct node* p, *q, *r;
    p = getnode(x);
    if(start==NULL){
        start = p;
    }
    else if(x < start->info){
        p->next = start;
        start = p;
    }
    else{
        q = start;
        r = NULL;
        while(q!=NULL && q->info < x){
            r = q;
            q = q->next;
        }
        r->next = p;
        p->next = q;
    }
}
int main(){
    start = NULL;
    insert_beg('z');
    insert_beg('y');
    insert_beg('C');
    traverse();
    insert_end('D');
    insert_end('H');
    traverse();
    cout<<count_nodes()<<endl;
    middleelement();
    middleelement2();
    reverse();
    traverse();
    orderedinsert('C');
    orderedinsert('F');
    orderedinsert('z');
    traverse();

    
    return 0;
}