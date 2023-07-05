# C++ OOP

## Class(1)

### private,protected,public

#### private(默认就是private)

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



我们如果在main函数中直接用对象输出学生的分数，就不能

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

protected   受保护的成员可以从同一类的其他成员（或从他们的“朋友”）访问，也可以从其派生类的成员访问。



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

> 上面是c++构造器一个简单的用法



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

> 😊有没有发现这样很麻烦呢？
>
> 其实在c++中有一个东西，叫`成员初始化列表`，看到上面的重载的第二个构造函数了吗？我们可以像下面这样写
>
> ```cpp
>      Rectangle(int _w, int _h) : width(_w), height(_h) {};
> ```
>
> 这样就大大简化了我们的构造函数书写啦！😊







---



### 指向类的指针（Pointers to Class)

在c++中，我们也 能用指针去指向类，然后通过指针调用类

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

> 😊既然这样，那我们就可以创建类数组啦
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
> > 关于指针和new这个我会后面参考`c++ primer plus`进行进一步说明



## Class(2)

### 重载运算符（overloading operators)



> **可重载运算符**
>
> ![image-20230705203726423](https://static.meowrain.cn/i/2023/07/05/xoxx73-3.webp)





> 为了方便说明，我这里直接拿牛客网的题来说明了，包括重载运算符有什么用

[重载小于号__牛客网 (nowcoder.com)](https://www.nowcoder.com/questionTerminal/e717e94202304f34b7ed95b2d31fce6b)



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





[加号运算符重载__牛客网 (nowcoder.com)](https://www.nowcoder.com/questionTerminal/b9e27fcf61fc4013875409ed78e0960b)

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

