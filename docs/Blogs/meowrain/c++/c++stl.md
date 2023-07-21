# C++ STL

## vector

### vector构造器

```cpp
#include <vector>
#include <iostream>
/* 
vector<T> v; // 采用模版类实现，默认构造函数
vector<T> v(T* v1.begin(), T* v1.end()); // 将v1[begin(), end())区间中的元素拷贝给本身
vector<T> v(int n, T elem); // 将n个elem拷贝给本身
vector<T> v(const vector<T> v1); // 拷贝构造函数
 */
int main(void) {
    std::vector<int> v; // 默认构造函数
    for(int i = 0;i<10;i++) {
        v.push_back(i);
    }

    //-----------------------------
    std::vector<int> v2{v.begin(),v.end()};// 拷贝构造函数
    for(int i = 0;i<10;i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;
    //-----------------------------


    //-----------------------------
    std::vector<int> v3(3,10); // 将3个10拷贝给本身
    for(int i = 0;i<3;i++) {
        std::cout << v3[i] << " ";
    }
    std::cout << std::endl;
    //-----------------------------

    //-----------------------------
    std::vector<int> v4(v3); // 拷贝构造函数
    for(int i = 0;i<3;i++) {
        std::cout << v4[i] << " ";
    }
    //-----------------------------

}
```

![](https://static.meowrain.cn/i/2023/07/21/ixxrov-3.webp)

### vector 方法

#### swap方法

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};

    std::cout << "Before swap: " << std::endl;
    std::cout << "v1: ";
    for (int num : v1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "v2: ";
    for (int num : v2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    v1.swap(v2);

    std::cout << "After swap: " << std::endl;
    std::cout << "v1: ";
    for (int num : v1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "v2: ";
    for (int num : v2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

```

![image-20230721114558777](https://static.meowrain.cn/i/2023/07/21/iy1x5v-3.webp)

#### vector 大小操作

bool empty(); // 判断容器是否为空

void resize(int num);
重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
若容器变短，则末尾超出容器长度的元素被删除
void resize(int num, T elem);
重新指定容器的长度为num，若容器变长，则以elem填充新位置。
若容器变短，则末尾超出容器长度的元素被删除

int capacity(); // 返回容器的容量
void reserve(int len);
 容器预留len个元素长度，预留位置不初始化，元素不可访问

```cpp
/* int size(); // 返回容器中的元素个数
bool empty(); // 判断容器是否为空

void resize(int num);
重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
若容器变短，则末尾超出容器长度的元素被删除
void resize(int num, T elem);
重新指定容器的长度为num，若容器变长，则以elem填充新位置。
若容器变短，则末尾超出容器长度的元素被删除

int capacity(); // 返回容器的容量
void reserve(int len);
 容器预留len个元素长度，预留位置不初始化，元素不可访问
 */
#include <iostream>
#include <vector>
int main(void)
{
    /* size empty */
    std::vector<int> v;
    std::cout << "size: " << v.size() << std::endl; //size: 0
    std::cout << "is empty? " << std::boolalpha << v.empty() << std::endl; //true
    /* 
    size: 0
    is empty? true
     */

    /* resize */
    std::vector<int> v2;
    for(int i = 0;i<10;i++) 
    {
        v2.push_back(i);
    }
    for(int i = 0;i<10;i++) 
    {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;
    v2.resize(5);
    std::vector<int>::iterator it = v2.begin();
    std::cout << "vector size:" << v2.size() << std::endl; //5
    std::cout << "v2 resize(5)" << std::endl;
    while(it != v2.end()) 
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    std::cout << "v2 resize(15,1)" << std::endl;
    v2.resize(15,1);
    it = v2.begin();
    while(it != v2.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;


/* capacity */
    std::vector<int> v3;
    for(int i = 0;i<100;i++) {
        v3.push_back(i);
    }
    std::cout << "vector size:" << v3.size() << std::endl; //100
    std::cout << "vector capacity: " << v3.capacity() << std::endl; //128

/* reverse */

    std::vector<char> v4;
    v4.reserve(1000);
    std::cout << "v4 capacity: " << v4.capacity() << std::endl;//v4 capacity: 1000
    return 0;
}
```

![image-20230721123245170](https://static.meowrain.cn/i/2023/07/21/kdrj2s-3.webp)





