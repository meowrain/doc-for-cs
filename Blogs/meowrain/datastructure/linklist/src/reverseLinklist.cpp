#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head;
void Insert(int num);
void Print();
void Reverse();
int main(void)
{
    head = NULL;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    Print();
    cout << "Now we will reverse this linklist!" << endl;
    Reverse();
    Print();
}
void Insert(int num)
{
    Node *temp = new Node();
    temp->data = num;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
}
void Print()
{
    cout << "The content in linklist:" << endl;
    Node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
void Reverse()
{
    if (head == NULL || head->next == NULL)
    {
        cout << "元素数量不足，无法进行翻转!" << endl;
        return;
    }
    Node *cur,*prev,*next;
    cur = head;
    prev = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}