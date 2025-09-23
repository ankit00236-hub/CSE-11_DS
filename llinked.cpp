
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
    Node *p, *r;
    p = GetNode();
    p->info = x;
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
    Node *p, *q, *r;
    p = *START;
    q = NULL;
    r = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->Next;
        q->Next = r;
    }
    *START = q;
    
}