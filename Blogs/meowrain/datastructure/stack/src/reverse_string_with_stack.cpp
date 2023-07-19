#include <iostream>
#include <string>
using namespace std;
class Stack
{
private:
    int MAX_SIZE = 5;
    char *stack = new char[MAX_SIZE];
    int top = -1;

public:
    void push_back(char n)
    {
        if (top == MAX_SIZE - 1)
        {
            MAX_SIZE *= 2;
            char *newStack = new char[MAX_SIZE];
            for (int i = 0; i <= top; i++)
            {
                newStack[i] = stack[i];
            }
            stack = newStack;
        }
        top++;
        stack[top] = n;
    }
    char pop()
    {
        if (top == -1)
        {
            return '\0';
        }
        else
        {
            char temp = stack[top]; // 存储栈顶元素
            top--;                  // 弹出栈顶元素
            return temp;            // 返回被弹出的栈顶元素
        }
    }
};
int main(void)
{
    string s = "hello";
    Stack stack;
        for (char c : s) {
        stack.push_back(c);
    }
    for (int j = 0; j < s.size(); j++)
    {
        cout << stack.pop();
    }
    return 0;
}