#include <iostream>
#include "listheader.hpp"
using namespace std;
void AddTwoLists(Node *first, Node *second, Node **result) {
    Node *p = first;
    Node *q = second;
    int carry = 0;
    while (p != NULL || q != NULL) {
        int sum = carry;
        if (p != NULL) {
            sum += p->info - '0'; // Convert char to int
            p = p->Next;
        }
        if (q != NULL) {
            sum += q->info - '0'; // Convert char to int
            q = q->Next;
        }
        carry = sum / 10;
        InsEnd(result, (sum % 10) + '0'); // Convert int back to char
    }
    if (carry > 0) {
        InsEnd(result, carry + '0'); // Convert int back to char
    }
}
int main() {
    Node *first = NULL;
    Node *second = NULL;
    Node *result = NULL;
    int num1,num2;
    cin>>num1>>num2;
    while(num1>0){
        InsEnd(&first,(num1%10)+'0');
        num1=num1/10;
    }
    while(num2>0){
        InsEnd(&second,(num2%10)+'0');
        num2=num2/10;
    }
    

    AddTwoLists(first, second, &result);
    cout << "First Number: ";
    reverse(&first);
    reverse(&second);
    Traverse(first);
    cout << "Second Number: ";
    Traverse(second);


    cout << "Resultant Sum: ";
    reverse(&result);
    Traverse(result);

    return 0;
}