#include <iostream>
using namespace std;
#include "linked.h"



Node* mergeLists(Node* head1, Node* head2) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = nullptr;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = (head1) ? head1 : head2;
    return dummy.next;
}


int main() {
    
    Node* head1 = new Node{1, nullptr};
    head1->next = new Node{3, nullptr};
    head1->next->next = new Node{5, nullptr};

    
    Node* head2 = new Node{2, nullptr};
    head2->next = new Node{4, nullptr};
    head2->next->next = new Node{6, nullptr};

    Node* merged = mergeLists(head1, head2);

    
    Node* temp = merged;
    cout << "Merged list: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    
    while (merged) {
        Node* del = merged;
        merged = merged->next;
        delete del;
    }
    return 0;
}
