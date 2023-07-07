# C++ OOP

## Class(1)

### private,protected,public

#### private(默认就是 private)

private 声明的类的私有成员只能由同一类的其他成员或者它们的朋友访问

```cpp
#include <iostream>
#include <string>
class Student {
private:
    int score;
public:
    std::string name;
    int age;
    Student(std::string _name,int _age,int _score) : name(_name),age(_age),score(_score){

    }
    void getScore(){
        std::cout << score << std::endl;
    }
};
int main(void) {
    Student s("meow",18,100);
    s.getScore();
}
```

![image-20230705191917170](https://static.meowrain.cn/i/2023/07/05/vqmqjj-3.webp)

我们如果在 main 函数中直接用对象输出学生的分数，就不能

```cpp
#include <iostream>
#include <string>
class Student {
private:
    int score;
public:
    std::string name;
    int age;
    Student(std::string _name,int _age,int _score) : name(_name),age(_age),score(_score){

    }
    void getScore(){
        std::cout << score << std::endl;
    }
};
int main(void) {
    Student s("meow",18,100);
    std::cout << s.score << std::endl;
}
```

![image-20230705192009344](https://static.meowrain.cn/i/2023/07/05/vr6m6j-3.webp)

![image-20230705192032009](https://static.meowrain.cn/i/2023/07/05/vrbig8-3.webp)

#### protected

protected 受保护的成员可以从同一类的其他成员（或从他们的“朋友”）访问，也可以从其派生类的成员访问。

```cpp
#include <iostream>
#include <string>
class Human {
protected:
    std::string name;
public:
    Human(std::string _name): name(_name){}
    void getHumanInfo() {
        std::cout << "Human name is: " << name << std::endl;
    } //同一类成员访问
};
class Student:Human{
public:
    int score;
    Student(std::string _name,int _score): Human(_name),score(_score) {

    }
    void getStudentInfo() {
        std::cout << "Student name is :" <<  name  << "\tStudent score is :" << score << std::endl;
    }
}; //派生类成员访问
int main(void) {
    Student s("meow",100);
    s.getStudentInfo();
    Human h("meow");
    h.getHumanInfo();
    return 0;
}
```

#### public

公共成员可以从对象可见的任何地方访问。

> 这里不作代码解释了。😊

---

### 实现类成员函数

```cpp
#include <iostream>
class Square {
    int width;
    int height;
public:
    void setWidth(int _width) {
        width = _width;
    }
    void setHeight(int _height) {
        height = _height;
    }
    int getArea();
    int getPerimeter();
};

int Square::getArea() {
    return width * height;
}
int Square::getPerimeter() {
    return 2*(width + height);
}
int main() {
    Square s;
    s.setHeight(10);
    s.setWidth(19);
    std::cout << s.getArea() << std::endl;
}
```

> 当然了，构造函数也可以在外面实现!😊

```cpp
#include <iostream>
#include <string>
class Student {
public:
    std::string name;
    int age;
    Student(std::string,int);
    void getStudentInfo() {
        std::cout << name << " " << age << std::endl;
    }
};
//在外面实现类的构造函数
Student::Student(std::string _name, int _age) : name(_name),age(_age){}
int main() {
    Student s("meow",10);
    s.getStudentInfo();
    return 0;
}

```

### 构造器（Constructors）

#### c++ 构造器（最简单的实例）

```cpp
#include <iostream>
class Rectangle {
    int width;
    int height;
public:
    Rectangle(int,int);
    void getArea();
};
Rectangle::Rectangle(int _w, int _h) {
    width = _w;
    height = _h;
}
void Rectangle::getArea() {
    std::cout << width * height << std::endl;
}
int main(void) {
    Rectangle r(100,100);
    r.getArea();
}
```

> 上面是 c++构造器一个简单的用法

#### 重载构造器（包括成员初始化列表）

> 试想一下，假如我要求用`Rectangle r`创建对象的时候，默认`width = 5`,`height = 5`,但是又要求能给`Rectangle 对象的成员变量赋值，比如让width = 10,height = 20`,`Rectangle r(10,20)`. 我们就得这么写

```cpp
#include <iostream>
class Rectangle {
    int width;
    int height;
public:
    Rectangle();
    Rectangle(int,int);
    void getArea(){
        std::cout << width*height << std::endl;
    }
};
Rectangle::Rectangle() {
    width = 5;
    height = 5;
}
Rectangle::Rectangle(int w, int h) {
    width = w;
    height = h;
}
int main(void) {
    Rectangle r;
    r.getArea(); //25
    Rectangle r2(10,15);
    r2.getArea(); //150
}
```

当然了，我们可以不在外面实现构造函数，直接在类里面写也是可以的

```cpp
#include <iostream>
class Rectangle {
    int width;
    int height;
public:
    Rectangle() {
        width = 5;
        height = 5;
    }
    Rectangle(int _w,int _h) {
        width = _w;
        height = _h;
    }
    void getArea(){
        std::cout << width*height << std::endl;
    }
};
int main(void) {
    Rectangle r;
    r.getArea(); //25
    Rectangle r2(10,15);
    r2.getArea(); //150
}
```

> 😊 有没有发现这样很麻烦呢？
>
> 其实在 c++中有一个东西，叫`成员初始化列表`，看到上面的重载的第二个构造函数了吗？我们可以像下面这样写
>
> ```cpp
>      Rectangle(int _w, int _h) : width(_w), height(_h) {};
> ```
>
> 这样就大大简化了我们的构造函数书写啦！😊

---

### 指向类的指针（Pointers to Class)

在 c++中，我们也 能用指针去指向类，然后通过指针调用类

```cpp
#include <iostream>
#include <string>
class Human {
    std::string name;
public:
    Human(std::string _name):name(_name){};
    void getHumanInfo() {
        std::cout << "Human name is :" << name << std::endl;
    }
};
int main() {
    //创建Human对象
    Human h("Mike");
    Human *human = &h;
    human->getHumanInfo(); //通过指针调用类的成员函数 //Human name is :Mike

    return 0;
}
```

> 😊 既然这样，那我们就可以创建类数组啦
>
> ```cpp
> #include <iostream>
>
> class Rectangle {
>     int width,height;
> public:
>     Rectangle(int _w,int _h):width(_w),height(_h){};
>     void getArea() {
>         std::cout << width*height << std::endl;
>     }
> };
> int main(void) {
>     Rectangle r(10,20);
>     Rectangle *ptr = new Rectangle[2]{{2,5},{3,6}};
>     ptr[0].getArea(); //10
>     ptr[1].getArea(); //18
>     delete []ptr;
>     return 0;
> }
>
> ```
>
> > 关于指针和 new 这个我会后面参考`c++ primer plus`进行进一步说明

## Class(2)

### 重载运算符（overloading operators)

> **可重载运算符**
>
> ![image-20230705203726423](https://static.meowrain.cn/i/2023/07/05/xoxx73-3.webp)

> 为了方便说明，我这里直接拿牛客网的题来说明了，包括重载运算符有什么用

[重载小于号\_\_牛客网 (nowcoder.com)](https://www.nowcoder.com/questionTerminal/e717e94202304f34b7ed95b2d31fce6b)

```cpp
#include <iostream>
using namespace std;

class Time {

    public:
        int hours;      // 小时
        int minutes;    // 分钟

        Time() {
            hours = 0;
            minutes = 0;
        }

        Time(int h, int m) {
            this->hours = h;
            this->minutes = m;
        }

        void show() {
            cout << hours << " " << minutes << endl;
        }

        // write your code here......
        bool operator<(Time b){
            if(hours > b.hours && minutes > b.minutes){
                return false;
            }
            else if(hours == b.hours && minutes == b.minutes) return false;
            else return true;
        }

};

int main() {
    int h, m;
    cin >> h;
    cin >> m;

    Time t1(h, m);
    Time t2(6, 6);

    if (t1<t2) cout<<"yes"; else cout<<"no";
    return 0;
}
```

[加号运算符重载\_\_牛客网 (nowcoder.com)](https://www.nowcoder.com/questionTerminal/b9e27fcf61fc4013875409ed78e0960b)

```cpp
#include <iostream>
using namespace std;

class Time {

  public:
    int hours;      // 小时
    int minutes;    // 分钟

    Time() {
        hours = 0;
        minutes = 0;
    }

    Time(int h, int m) {
        this->hours = h;
        this->minutes = m;
    }

    void show() {
        cout << hours << " " << minutes << endl;
    }

    // write your code here......
    Time operator+(Time b) {
        int sum_hours = hours + b.hours;
        int sum_minutes = minutes + b.minutes;
        if (sum_minutes >= 60) {
            sum_minutes -= 60;
            sum_hours += 1;
        }
        Time sum(sum_hours, sum_minutes);
        return sum;
    }

};

int main() {

    int h, m;
    cin >> h;
    cin >> m;

    Time t1(h, m);
    Time t2(2, 20);

    Time t3 = t1 + t2;
    t3.show();

    return 0;
}
```

### Copy Constructor

拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。拷贝构造函数通常用于：

通过使用另一个同类型的对象来初始化新创建的对象。

复制对象把它作为参数传递给函数。

复制对象，并从函数返回这个对象。

如果在类中没有定义拷贝构造函数，编译器会自行定义一个。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。拷贝构造函数的最常见形式如下：

```cpp
classname (const classname &obj) {
   // 构造函数的主体
}
```

```cpp
#include <iostream>
using namespace std;
class Person {
public:
    string name;
    int age;
    Person() {
        name = "meow";
        age = 10;
    }
    Person(string _name,int _age) {
        name = _name;
        age = _age;
    }
    Person(const Person& other) {
        name = other.name;
        age = other.age;
    }
    void getInfo() {
        cout << name << " " << age << "  " << endl;
    }
};

int main() {
    Person p("mew",19);
    Person p1 = p;
    Person p2(p);
    p.getInfo();
    p1.getInfo();
    p2.getInfo();
    return 0;

}
```

> p1 是通过使用赋值语句来初始化的，即 Person p1 = p;。这实际上是一种隐式的赋值操作，编译器会使用 copy constructor 来创建 p1 对象，并将 p 对象的值复制到 p1 对象中。

> 而 p2 是通过直接调用 copy constructor 来初始化的，即 Person p2(p);。这是一种显式调用 copy constructor 的方法，它直接使用现有对象 p 来创建新对象 p2，不需要使用赋值语句。

### Copy assignment(复制赋值操作符)

是 C++中的一个运算符，用于将一个对象的值复制到另一个对象中。它通常用于将一个已经存在的对象的值赋给另一个已经存在的对象，从而使它们具有相同的值。

语法格式：

```cpp
classname& operator=(const classname& other)
```

> 默认情况下，C++会提供一个浅复制的 copy assignment 运算符

看一个例子：

```cpp
#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    Person() {
        name = "meo";
        age = 12;
    }

    Person(std::string _name, int _age) : name(_name), age(_age) {

    }

    // copy constructor
    Person(const Person &other) {
        name = other.name;
        age = other.age;
    }

    // copy assignment
    Person &operator=(const Person &other) {
        name = other.name;
        age = other.age;
        return *this;
    }

};


int main(void) {
    Person p1("meow", 12);
    Person p2;
    p2 = p1;
    std::cout << "p1.name " << p1.name << " age: " << p1.age << std::endl;
    std::cout << "p2.name " << p2.name << " age: " << p2.age << std::endl;
    return 0;
}
```

浅复制是指简单地将现有对象的成员变量的值复制到新对象中。如果成员变量是基本类型，那么浅复制是没有问题的，因为它们只是简单的值。但是，如果成员变量是指针，浅复制可能会导致问题。在这种情况下，浅复制只会复制指针本身，而不会复制指针指向的数据。这意味着新对象和现有对象将共享同一块数据，这可能会导致内存泄漏或数据损坏。

深复制是指将现有对象的成员变量的值复制到新对象中，并复制指针指向的数据。这意味着新对象将有自己的数据副本，与现有对象完全独立。这通常需要手动实现，因为 C++默认提供的复制构造函数和赋值运算符只会执行浅复制。

### 友元

友元是一种特殊的访问权限，允许一个函数或类访问另一个类的私有或受保护成员。

友元有三种：

- 友元函数
- 友元类
- 友元成员函数

#### 友元函数

创建友元函数得第一步 hi 把原型放在类声明中，在原型声明前面加上`friend`

> 需要注意的是，友元函数并不是 MyClass 的成员函数，它是一个独立的函数，只是被声明为 MyClass 的友元函数。

```cpp
#include <iostream>
class Person {
private:
    std::string name;
    int age;
public:
    Person(std::string _name,int _age) : name(_name),age(_age){}
    friend void printValue(Person &p) {
        std::cout << "Person name: " << p.name << "\t" <<
        "Person age: " << p.age << std::endl;
    }

    /* 在友元函数中，我们能访问Person类的私有成员变量 */
};
int main(void) {
    Person p("meow",18);
    printValue(p); //友元函数不是类Person的成员函数
    return 0;
}
```

#### 友元类

友元类是指一个类可以访问另一个类的私有成员，这使得它们之间的关系更加密切。

例子：
```cpp
#include <iostream>
class MainClass {
private:
    std::string name;
    int age;
public:
    MainClass() {
        name = "Main class";
        age = 129;
    }
    friend class FriendClass;
};
class FriendClass {
private:
    std::string name;
    int age;
public:
    FriendClass() {
        name = "friend";
        age = 120;
    }
    void printMainClassInfo(MainClass &m) {
        std::cout << "MainClass!!!!" << std::endl;
        std::cout << m.name << " " << m.age << std::endl;
    }
    void printFriendClassInfo() {
        std::cout << "Friend!!!" << std::endl;
        std::cout << name << " " << age << std::endl;
    }
};
int main(void) {
    MainClass m;
    FriendClass f;
    f.printFriendClassInfo();
    f.printMainClassInfo(m);
    return 0;
}

```
![1688739423295](image/C++OOP/1688739423295.png)



