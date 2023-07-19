#include <iostream>

// 定义一个结构体Node，表示链表的节点
struct Node
{
    int data;   // 存储节点的数据
    Node *next; // 指向下一个节点的指针
};

int main()
{
    Node *A = NULL;          // 定义一个指向链表头节点的指针，初始值为NULL
    Node *temp = new Node(); // 创建一个新的节点
    temp->data = 200;        // 设置新节点的数据为200
    temp->next = NULL;       // 新节点的下一个节点为NULL
    A = temp;                // 将新节点设置为链表的头节点

    temp = new Node(); // 再次创建一个新的节点
    temp->data = 4;    // 设置新节点的数据为4
    temp->next = NULL; // 新节点的下一个节点为NULL

    Node *temp1 = A; // 定义一个指针temp1，初始值指向链表头节点
    // 遍历链表以到达链表最后一个节点
    while (temp1->next != NULL)
    {
        temp1 = temp1->next; // 将temp1指向下一个节点，直到到达链表最后一个节点
    }
    temp1->next = temp; // 将新节点添加到链表的最后一个节点后面，实现插入操作

    std::cout << "插入成功；输出链表内容" << std::endl; // 输出提示信息

    while (A != NULL) // 遍历链表，输出链表数据
    {
        std::cout << A->data << std::endl; // 输出当前节点的数据
        A = A->next;                       // 将指针A指向下一个节点，继续遍历链表
    }
    delete temp;
    delete temp1;
    return 0;
}