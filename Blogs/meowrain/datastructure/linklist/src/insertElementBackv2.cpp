#include <iostream>
struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;
void Insert(int);
void Print();
int main(void)
{
    int n;
    std::cout << "请输入你要存的数字个数：" << std::endl;
    std::cin >> n;
    std::cout << "请输入你存的数字： " << std::endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        Insert(x);
    }
    Print();
    return 0;
}
void Insert(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void Print()
{
    std::cout << "链表内容如下； " << std::endl;
    Node *curr = head;
    while (curr != NULL)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
}