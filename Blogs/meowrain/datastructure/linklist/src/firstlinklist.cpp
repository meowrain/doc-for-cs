// 第一个链表程序
#include <iostream>
struct Node
{
    int data;
    Node *next;
};
int main()
{
    Node *A = NULL;
    // Node* temp = (Node*)malloc(sizeof(Node));
    Node *temp = new Node();
    (*temp).data = 200;
    (*temp).next = NULL;
    A = temp;
    std::cout << A->data << std::endl;
    delete temp;
    return 0;
}