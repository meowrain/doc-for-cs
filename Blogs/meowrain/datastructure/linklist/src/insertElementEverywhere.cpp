#include <iostream>
struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;
void Insert(int, int);
void Print();
int main()
{
    std::cout << "插入位置： " << std::endl;
    int n;
    std::cin >> n;
    std::cout << "插入节点数据： " << std::endl;
    int x;
    std::cin >> x;
    Insert(n,x);
    Print();
    return 0;
}
void Insert(int n, int x)
{
    if (n == 1)
    {
        Node *temp = new Node();
        temp->data = x;
        temp->next = head;
        head = temp;
        return;
    }
    Node *cur = head;
    for (int i = 1; i < n - 1 && cur != NULL; i++)
    {
        cur = cur->next;
    }
    if (cur == NULL)
    {
        std::cout << "Can not insert!" << std::endl;
        return;
    }
    Node *temp = new Node();
    temp->data = x;
    temp->next = cur->next;
    cur->next = temp;
}
void Print() {
    std::cout << "链表内容如下：" << std::endl;
    Node* curr = head;
    while(curr != NULL) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}