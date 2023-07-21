
# C++ main函数参数

int argc 和 char* argv[] 是 C++ 中 main 函数的标准参数，用于接收程序启动时的命令行参数。

argc 表示命令行参数的数量，包括程序本身的名称。因此，当执行程序时，在命令行中输入的参数个数加一就是 argc 的值。

argv[] 是一个字符指针数组，其中 argv[0] 存储的是程序本身的名称（即执行程序时输入的第一个参数），而 argv[1] 到 argv[argc-1] 存储的是程序启动时输入的其它参数。这些参数都是以字符串的形式传递的，因此 argv 数组中的每个元素都是一个指向以 null 结尾的字符串的指针。

代码

```cpp
#include <iostream>
int main(int argc,char* argv[]) {
    std::cout << "Program name is " << argv[0] << std::endl;
    std::cout << "The number of arguments is:" << argc << std::endl;
    for(int i = 1;i<argc;i++) {
        std::cout << "Arguments: " << argv[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

![](https://static.meowrain.cn/i/2023/07/18/1142j1g-3.webp)
