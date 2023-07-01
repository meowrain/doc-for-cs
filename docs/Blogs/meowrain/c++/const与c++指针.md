# const 与c++指针
> cosnt 是c++中用于声明常量的关键字。可以用来修饰变量，指针，函数参数和函数返回值
> 使用const关键字能让变量的值不能被修改，或者函数的参数和返回值不能修改

## 防止通过指针修改数据
> 通过把指针声明为指向常量的指针，可以防止通过指针修改数据，这对于传递函数参数或者在函数中使用指针时非常有用，可以确保被指向的数据不会被修改

<font color="red">示例：</font>
```cpp
#include <iostream>
void print(const int *ptr){
    //ptr指向的值不能被修改
    // *ptr = 10;//错误，不能修改指针指向的值
    std::cout << *ptr << std::endl;
}
int main(void) {
    int x = 5;
    print(&x);
    return 0;
}
```

## 声明常量指针
> ### 什么是常量指针?
> 使用const 关键字将指针本身声明为常量指针，即指针的值不能被修改。这意味着指针始终指向同一个地址，不能指向其他地址
```cpp
#include <iostream>
int main(void){
    int x = 5;
    int s = 6;
    int *const str = &x;
    *ptr = 10; //可以通过指针修改指针指向地址上的值
    // ptr = &6; //错误，不能修改指针的值，也就是指针变量里面存储的地址
}
```

## 常量指针指向常量
> 通过将指针声明为指向常量的常量指针，不能修改指针的值，也不能修改指针指向的值
> 这样确保指针不会指向其他地址，也不能修改所指向的值


```cpp
#include <iostream>
int main(void) {
    const int x = 5;
    const int *const str = &x; //ptr是一个指向常量的常量指针
    // *ptr = 10; //错误，不能修改指针所指向的值
    // ptr = nullptr; //错误，不能修改指针的值
}
```


---

## Summary
```cpp
#include <iostream>
int main(void)
{
    int x = 5;
    const int *str = &x;
    //这样的指针是没办法修改指针指向的值，str是一个指向常量int的指针
    int m = 6;
    int* const st = &m; //常量指针，不能修改指针的值

}
```

`int* const a` ==> 常量指针，不能修改指针的值  这里和`int const *a`是等同的
`const int *a` ==> 指向常量的指针，不能指针修改指向的值
`const int* const a` ==> 指向常量的常量指针，上面两种都不行
