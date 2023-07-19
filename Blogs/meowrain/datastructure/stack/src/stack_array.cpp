#include <iostream>
using namespace std;

int MAX_SIZE = 10;              // 定义栈的最大容量
int *Stack = new int[MAX_SIZE]; // 动态分配数组空间
int top = -1;                   // 栈顶指针初始化为-1

void push_back(int n)
{ // 入栈操作
    if (top == MAX_SIZE - 1)
    { // 如果栈已满，扩容两倍
        MAX_SIZE = 2 * MAX_SIZE;
        int *newStack = new int[MAX_SIZE]; // 动态分配更大的数组空间
        for (int i = 0; i <= top; i++)
        { // 将原数组中的元素复制到新数组中
            newStack[i] = Stack[i];
        }
        Stack = newStack; // 将指针指向新数组的首地址
    }
    top = top + 1;  // 栈顶指针加1
    Stack[top] = n; // 将元素压入栈顶
}

void pop()
{                  // 出栈操作
    top = top - 1; // 栈顶指针减1
}

bool IsEmpty()
{ // 判断栈是否为空
    if (top == -1)
    { // 栈顶指针为-1时，栈为空
        return true;
    }
    return false;
}

int top_element()
{ // 返回栈顶元素
    return Stack[top];
}

int search(int n)
{ // 查找元素在栈中的位置
    for (int i = 0; i <= top; i++)
    { // 从栈底开始遍历栈中的所有元素
        if (Stack[i] == n)
        {             // 如果找到指定的元素
            return i; // 返回元素在栈中的位置
        }
    }
    return -1; // 否则返回-1
}

int main(void)
{
    // 测试代码
    for (int i = 0; i < 200; i++)
    { // 入栈200个元素
        push_back(i);
    }
    while (!IsEmpty())
    { // 出栈并输出元素
        cout << top_element() << " ";
        pop();
    }
    cout << search(3) << endl; // 查找元素3在栈中的位置
    delete[] Stack;            // 释放动态分配的数组空间
    return 0;
}