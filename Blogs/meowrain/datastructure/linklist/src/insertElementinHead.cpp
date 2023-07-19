#include <iostream>  
// 定义一个结构体Node，表示链表的节点  
struct Node  
{  
    int data; // 存储节点的数据  
    Node *next; // 指向下一个节点的指针  
};  
// 定义主函数  
int main(void)  
{  
    Node *head = NULL; // 定义一个指向链表头节点的指针，初始值为NULL  
    Node *temp1 = new Node(); // 创建一个新的节点  
    temp1->data = 2; // 设置新节点的数据为2  
    temp1->next = NULL; // 新节点的下一个节点为NULL  
    head = temp1; // 将新节点设置为链表的头节点  
    temp1 = new Node(); // 再次创建一个新的节点  
    temp1->data = 1; // 设置新节点的数据为1  
    temp1->next = head; // 将新节点的下一个节点指向原来的头节点head  
    head = temp1; // 将链表的头节点指向新节点  
    temp1 = new Node(); // 再次创建一个新的节点  
    temp1->data = 0; // 设置新节点的数据为0  
    temp1->next = head; // 将新节点的下一个节点指向原来的头节点head  
    head = temp1; // 将链表的头节点指向新节点  
    std::cout << head->data << head->next->data << head->next->next->data << std::endl; // 输出链表的数据，依次输出头节点、第二个节点和第三个节点的数据  
}