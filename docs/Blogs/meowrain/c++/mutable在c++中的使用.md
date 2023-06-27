# mutable

在C++中，`mutable`关键字用于修饰类的成员变量。当一个成员变量被声明为`mutable`时，它可以在`const`成员函数中被修改，即使该函数不应该修改对象的状态。

# mutable在c++中的使用

![image-20230627211616676](https://static.meowrain.cn/i/2023/06/27/yzx17d-3.webp)

上面这个代码中，因为`get_value`和`set_value`被声明为const成员函数，所以它不能修改类中的其他值,然而因为`value_`被声明为`mutable`，所以它又变成可修改的了

---



# 代码示例

我的代码示例：

```cpp
#include <iostream>
#include <string>

class Entity {
private:
    std::string m_Name;
    mutable int m_DebugCount = 0;
public:
    Entity(const std::string& _name){
        m_Name = _name;
    }
    const std::string& GetName() const{
        return m_Name;
    }
    int get_num() const{
        return m_DebugCount;
    }
    void add_num(int n) const{
        m_DebugCount += n;
    }
};
int main(void) {
    Entity e("meowrain");
    const std::string& name = e.GetName();
    std::cout << name << std::endl;
    std::cout << e.get_num() << std::endl;
    e.add_num(3);
    std::cout << e.get_num() << std::endl;

    const Entity e1("Jack");
    const std::string& name2 = e1.GetName();

}
```




构造函数 `Entity(const std::string& _name)`: 用于创建Entity对象并初始化m_Name成员变量。

成员函数 `const std::string& GetName() const`: 返回Entity对象的名称m_Name。由于该函数不会修改对象的状态，因此被声明为const成员函数。

成员函数 `int get_num() const`: 返回Entity对象的m_DebugCount值。由于该函数不会修改对象的状态，因此被声明为const成员函数。

成员函数 `void add_num(int n) const`: 将参数n的值加到Entity对象的m_DebugCount上。由于该函数会修改对象的状态，但是m_DebugCount被声明为mutable，所以即使在const成员函数中也可以修改它。

函数 `int main()`: 程序的入口函数。在该函数中创建了Entity对象e和e1，并调用它们的成员函数进行操作和输出。
