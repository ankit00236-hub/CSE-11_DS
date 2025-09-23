#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void traverse(Node* start) {
    Node* temp = start;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    

    
}
