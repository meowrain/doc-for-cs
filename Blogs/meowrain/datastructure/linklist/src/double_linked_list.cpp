#include <iostream>
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
Node *head;
Node *GetNewNode(int);
void InsertAtHead(int);
void InsertAtTail(int);
void Print();
void ReversePrint();
int main(void)
{
    head = NULL;
    InsertAtHead(2);
    InsertAtHead(4);
    InsertAtHead(6);
    InsertAtHead(8);
    Print();
    std::cout << std::endl;
    ReversePrint();
    head = NULL;
    std::cout << std::endl;
    InsertAtTail(2);
    InsertAtTail(4);
    InsertAtTail(6);
    InsertAtTail(8);
    Print();
    std::cout << std::endl;
    ReversePrint();
    return 0;
}
Node *GetNewNode(int x)
{
    Node *newNode = new Node();
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = x;
    return newNode;
}

void InsertAtHead(int x)
{
    Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void InsertAtTail(int x)
{
    Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void Print()
{
    std::cout << "The content of LinkList: " << std::endl;
    Node *cur = head;
    while (cur != NULL)
    {
        std::cout << cur->data << " ";
        cur = cur->next;
    }
}
void ReversePrint()
{
    std::cout << "The Reverse content of LinkList: " << std::endl;
    Node *cur = head;
    if (cur == NULL)
        return;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    while (cur != NULL)
    {
        std::cout << cur->data << " ";
        cur = cur->prev;
    }
}