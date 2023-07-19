#include <iostream>
using namespace std;
class Stack
{
private:
    int MAX_SIZE = 10;              // 定义栈的最大容量
    int *Stack = new int[MAX_SIZE]; // 动态分配数组空间
    int top = -1;

public:
    void push_back(int val)
    {
        if (top >= MAX_SIZE - 1)
        {
            MAX_SIZE *= 2;
            int *newStack = new int[MAX_SIZE];
            for (int i = 0; i <= top; i++)
            {
                newStack[i] = Stack[i];
            }
            Stack = newStack;
        }
        top++;
        Stack[top] = val;
    }
    void pop()
    {
        top--;
    }
    bool is_empty()
    {
        return top == -1; // 判断栈是否为空
    }
    int top_element()
    {
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
};
int main(void)
{
    Stack s;
    for (int i = 0; i <= 200; i++)
    {
        s.push_back(i);
    }
    while (!s.is_empty())
    {
        cout << s.top_element() << " ";
        s.pop();
    }
    
    return 0;
}