# 计算c/c++程序运行时间

## C语言程序


```c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    // 在这里执行你的程序逻辑
    // ...

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("程序运行时间: %f 秒\n", cpu_time_used);

    return 0;
}
```


## C++程序

```c++
#include <iostream>
#include <chrono>

int main() {
    // 获取当前时间点
    auto start_time = std::chrono::high_resolution_clock::now();

    // 在这里执行你的程序逻辑
    // ...

    // 获取结束时间点
    auto end_time = std::chrono::high_resolution_clock::now();

    // 计算时间差
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // 输出运行时间
    std::cout << "程序运行时间: " << duration.count()/1e6 << " 秒" << std::endl;

    return 0;
}

```


## Linux time命令
使用time命令

```bash
time ./your_program
```

例如，编译了一个c++程序，叫main
那么我就可以执行


```bash
time ./main
```

来得到程序运行时长