#include <iostream>
#include <stack>
#include <string>

// 括号匹配函数
bool paren(const std::string &input)
{
    std::stack<char> s;
    for (const char c : input)
    {
        // 左括号入栈
        if (c == '(' || c == '[' || c == '{')
        {
            s.push(c);
            continue;
        }
        // 右括号匹配
        if (s.empty() ||
            (c == ')' && s.top() != '(') ||
            (c == '}' && s.top() != '{') ||
            (c == ']' && s.top() != '['))
        {
            return false;
        }

        // 匹配成功，弹出左括号
        s.pop();
    }
    // 判断栈是否为空
    return s.empty();
}

int main()
{
    const std::string input1 = "({[]})";
    const std::string input2 = "({[})";
    std::cout << std::boolalpha << paren(input1) << '\n';
    std::cout << std::boolalpha << paren(input2) << '\n';
    /*
    std::boolalpha 是一个 std::ios 标志，用于指示流输出布尔值时使用文字形式输出，即将 true 输出为 "true"，将 false 输出为 "false"。

    默认情况下，流输出布尔值时使用整数形式输出，即将 true 输出为 1，将 false 输出为 0。如果需要输出文字形式，可以使用 std::boolalpha 标志。

    在代码中，std::cout << std::boolalpha << paren(input1) << '\n'; 表示将 std::boolalpha 标志应用到 std::cout 流上，以确保输出的布尔值使用文字形式。
     */
    return 0;
}