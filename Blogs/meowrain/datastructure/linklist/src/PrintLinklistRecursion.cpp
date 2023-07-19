/* 这个程序，我们采用递归的方式进行打印链表 */
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head;
void Print(Node *p);
void Insert(int data);
void ReversePrint(Node *p);
int main(void) {
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    cout << "Normal Print the Linklist: " << endl;
    Print(head);
    cout << endl;
    cout << "Reverse Print the Linklist: " << endl;
    ReversePrint(head);
    return 0;
}
void Insert(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
    } else {
        Node *curr = head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void Print(Node* p){
    //recursion
    if(p == NULL) return;
    cout << p->data << " ";
    Print(p->next); //Recursive call
}
void ReversePrint(Node* p){
    //recursion
    if(p == NULL) return;
    ReversePrint(p->next); //Recursive call
    cout << p->data << " ";
}