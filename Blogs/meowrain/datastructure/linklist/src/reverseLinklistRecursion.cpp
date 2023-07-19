#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head;
void Insert(int);
void Print(Node* p);
void Reverse_LinkList(Node* p);
int main(void)
{
    head = NULL;
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    cout << "Normal LinkList:";
    Print(head);
    Reverse_LinkList(head);
    cout << "Reverse LinkList:";
    Print(head);
    return 0;
}
void Insert(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
    }else{
        Node* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}

void Print(Node* p){
    if(p == NULL) {
        cout << endl;
        return;
    }
    cout << p->data << " ";
    Print(p->next);
}
void Reverse_LinkList(Node* p) {
    if(p->next == NULL) {
        head = p;
        return;
    }
    Reverse_LinkList(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}