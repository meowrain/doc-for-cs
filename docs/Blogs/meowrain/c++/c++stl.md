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

#### assign方法

`std::vector` 的 `assign()` 是一个成员函数，用于将容器重置并赋予新的元素值。`assign()` 可以以不同的方式使用，这取决于传递给它的参数。以下是 `assign()` 的应用示例：





使用单一值初始化容器：

 ```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector;

    // 使用 assign() 将容器重置为包含 5 个元素，每个元素的值都是 42
    myVector.assign(5, 42);

    // 输出容器的元素
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }

    std::cout << std::endl;
    return 0;
}

 ```

> 42 42 42 42 42







使用范围内的值初始化容器：

```cpp
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> ve;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ve.assign(arr, arr + 10);
    for (auto &ele : ve)
    {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

> 1 2 3 4 5 6 7 8 9 10 





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





vector插入和删除操作

```cpp
/* 
insert(const_iterator pos, T elem); // 在pos位置处插入元素elem
insert(const_iterator pos, int n, T elem); // 在pos位置插入n个元素elem
insert(pos, beg, end); // 将[beg, end)区间内的元素插到位置pos
push_back(T elem); // 尾部插入元素elem
pop_back(); // 删除最后一个元素

erase(const_iterator start, const_iterator end); // 删除区间[start, end)内的元素
erase(const_iterator pos); // 删除位置pos的元素

clear(); // 删除容器中的所有元素
 */
#include <iostream>
#include <vector>
#include <iterator>
int main(void) {
    std::vector<int> ve;
    for(int i = 0;i<10;i++) {
        ve.push_back(i);
    }
    auto it = ve.begin(); //迭代器指针指向容器开头
    std::advance(it,2); //迭代器指针向后移动两位
    ve.insert(it,12); //使用insert把12插入到Index为2得地方
    it = ve.begin();
    while(it!=ve.end()){
        std::cout << *it << " ";
        it++;
    }//0 1 12 2 3 4 5 6 7 8 9 
    std::cout << std::endl;
    ve.pop_back(); //弹出尾部元素
    it = ve.begin();
    for(auto& ele : ve) {
        std::cout << ele << " ";
    }//0 1 12 2 3 4 5 6 7 8 
    std::cout << std::endl;

    std::vector<int> ve2;
    for(int i = 1;i<=10;i++) {
        ve2.push_back(i);
    }
    auto it1 = ve2.begin();
    std::advance(it1,5);
    auto it2 = std::next(it1,3);
    ve2.erase(it1,it2);
    auto iter = ve2.begin();
    for(auto& ele : ve2) {
        std::cout << ele << " ";
    }
    std::cout << std::endl;
    ve2.clear();
    return 0;
}
```

#### vector数据存取操作

```cpp
/* 

vector 数据存取操作
T& at(int idx); // 返回索引idx所指的数据，如果idx越界，抛出out_of_range异常
T& operator[](int idx); // 返回索引idx所指的数据，如果idx越界，运行直接报错

T& front(); // 返回首元素的引用
T& back(); // 返回尾元素的引用

 */

#include <iostream>
#include <vector>

int main(void) {
    std::vector<int> ve;
    for(int i = 0;i<10;i++) {
        ve.push_back(i);
    }
    std::cout << ve.at(0) << " "; // 0
    std::cout << std::endl;
    std::cout << ve[0] << " "; //0
    std::cout << std::endl;
    std::cout << ve.front() << std::endl; //0
    std::cout << ve.back() << std::endl; //9
    return 0;

}
```

### vector的遍历

迭代器遍历

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // 使用迭代器遍历
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    return 0;
}

```

for循环

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // 使用范围-based for 循环遍历
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }

    std::cout << std::endl;
    return 0;
}

```

