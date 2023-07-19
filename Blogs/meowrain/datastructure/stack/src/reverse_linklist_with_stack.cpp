#include <iostream>
#include <stack>
using namespace std;

// 链表节点结构体
struct Node
{
    int data;       // 数据
    Node *next;     // 指向下一个节点的指针
};

// 链表类
class LinkList
{
public:
    Node *head = nullptr;   // 链表的头节点

    // 在链表末尾插入一个节点
    void Insert(int val)
    {
        Node *temp = new Node();    // 创建新节点
        temp->data = val;           // 设置新节点的数据
        temp->next = nullptr;       // 新节点的下一个节点指针为nullptr

        if (head == nullptr)        // 如果链表为空
        {
            head = temp;            // 将新节点设置为头节点
            return;
        }
        else                        // 如果链表不为空
        {
            Node *cur = head;
            while (cur->next != nullptr)    // 遍历链表找到最后一个节点
            {
                cur = cur->next;
            }
            cur->next = temp;       // 将新节点连接到最后一个节点的后面
        }
    }

    // 打印链表中的所有元素
    void Print()
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }

    // 将链表逆序
    void Reverse()
    {
        stack<Node *> s;   // 创建一个栈，用来存储链表中的所有节点

        Node *cur = head;
        while (cur != nullptr)      // 将链表中的所有节点都压入栈中
        {
            s.push(cur);
            cur = cur->next;
        }

        head = s.top();     // 将栈顶元素设置为链表的新头节点
        s.pop();

        cur = head;         // 遍历链表，将栈中的节点依次弹出并连接起来
        while (!s.empty())
        {
            cur->next = s.top();
            s.pop();
            cur = cur->next;
        }
        cur->next = nullptr;    // 最后一个节点的下一个节点指针为nullptr
    }
};

int main(void)
{
    LinkList l;     // 创建一个链表对象

    // 向链表中插入元素
    l.Insert(1);
    l.Insert(2);
    l.Insert(3);
    l.Insert(4);
    l.Insert(5);
    l.Insert(6);
    l.Insert(7);

    // 打印原始链表
    l.Print();
    cout << endl;

    // 将链表逆序
    l.Reverse();

    // 打印逆序后的链表
    l.Print();
    cout << endl;

    return 0;
}