#include "MyHeaderFile.cpp"
#include <iostream>
using namespace std;
int main() {
    Node* start = NULL;

    InsBeg(&start, 'A');
    InsBeg(&start, 'B');
    InsEnd(&start, 'C');
    InsEnd(&start, 'D');

    cout << "Linked List: ";
    Traverse(start);

    cout << "Number of nodes: " << countnode(&start) << endl;

    cout << "Middle element: ";
    middleelement(start);
    deleteafter(&start->Next); 
    deletenode(&start, 'A');
    cout << "Linked List after deletion: ";
    Traverse(start);
    return 0;
}