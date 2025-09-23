#define MyListHeader
#include <iostream>
using namespace std;
struct Node {
    char info;
    struct Node *Next;
};
Node* GetNode() {
    Node *p = new Node; 
    return p;
}
void InsBeg(Node **START, char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = *START;
    *START = p;
}
void Traverse(Node *START) {
    Node *p = START;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->Next;
    }
    cout << endl;
}
void InsEnd(Node **START, char x) {
    Node *q, *p;
    p = GetNode();
    p->info = x;
    p->Next = NULL;
    if (*START == NULL) {
        *START = p;
    } 
    else {
        q = *START;
        while (q->Next != NULL) {
            q = q->Next;
        }
        q->Next = p;
    }
}
int countnode(Node **START) {
    Node *p = *START;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->Next;
    }
    return count;
}
int middleelement(Node *START) {
    int c = countnode(&START);
    int i = 1;
    Node *p = START;
    for(i = 1; i < c / 2; i++) {
        p = p->Next;
    }
    cout << p->info << endl;
    return 0;
}
void InsAfter(Node **q, char x) {
    Node *p,*r;
    p = GetNode();
    p->info = x;
    p->Next = (*q)->Next;
    r = (*q)->Next;
    (*q)->Next = p;
    p->Next = r;
}
int midelement(Node *START) {
    Node *T, *R;
    T = START;
    R = START->Next;
    while (R != NULL && R->Next != NULL) {
        T = T->Next;
        R = R->Next;
        R = R->Next;
    }
    cout << T->info << endl;
    return 0;
}
void reverse(Node **START) {
    Node *prev, *curr, *next;
    prev = NULL;
    curr = *START;
    while (curr != NULL) {
        next = curr->Next;
        curr->Next = prev;
        prev = curr;
        curr = next;
    }
    *START = prev;
}
int deletenode(Node **START, char x) {
    Node *p, *q;
    if (*START == NULL) {
        cout << "List is empty" << endl;
        return 0;
    }
    if ((*START)->info == x) {
        p = *START;
        *START = (*START)->Next;
        delete p;
        return 0;
    }
    q = *START;
    p = (*START)->Next;
    while (p != NULL && p->info != x) {
        q = p;
        p = p->Next;
    }
    if (p == NULL) {
        cout << "Element not found" << endl;
        return 0;
    }
    q->Next = p->Next;
    delete p;
    return 0;
}
int deleteafter(Node **q) {
    Node *p;
    if (*q == NULL) {
        cout << "List is empty" << endl;
        return 0;
    }
    if ((*q)->Next == NULL) {
        cout << "No node to delete after given node" << endl;
        return 0;
    }
    p = (*q)->Next;
    (*q)->Next = p->Next;
    delete p;
    return 0;
}
int deletebeg(Node **START) {
    Node *p;
    if (*START == NULL) {
        cout << "List is empty" << endl;
        return 0;
    }
    p = *START;
    *START = (*START)->Next;
    delete p;
    return 0;
}
int deleteend(Node **START) {
    Node *p, *q;
    if (*START == NULL) {
        cout << "List is empty" << endl;
        return 0;
    }
    if ((*START)->Next == NULL) {
        p = *START;
        *START = NULL;
        delete p;
        return 0;
    }
    q = *START;
    p = (*START)->Next;
    while (p->Next != NULL) {
        q = p;
        p = p->Next;
    }
    q->Next = NULL;
    delete p;
    return 0;
}