#include <iostream>
#include"MyHeaderFile.cpp"
using namespace std;
void ordered_instertion(Node **START, char x) {
    Node *p, *q, *r;
    p = GetNode();
    p->info = x;
    p->Next = NULL;
    if (*START == NULL || (*START)->info >= x) {
        p->Next = *START;
        *START = p;
    } 
    else {
        q = *START;
        r = NULL;
        while (q != NULL && q->info < x) {
            r = q;
            q = q->Next;
        }
        p->Next = q;
        r->Next = p;
    }
}

int main() {
