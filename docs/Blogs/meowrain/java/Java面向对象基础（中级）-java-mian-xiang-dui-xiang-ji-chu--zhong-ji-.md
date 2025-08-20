---
title: Java面向对象基础（中级）
date: 2022-12-10 07:14:19.553
updated: 2022-12-13 06:14:22.729
url: https://meowrain.cn/archives/java-mian-xiang-dui-xiang-ji-chu--zhong-ji-
categories: 
- 笔记
- Java
tags: 
- java
- OOP
---

# Java面向对象基础（中级）
Consolas, 'Courier New', monospace
## 包

### 包的三大作用

1.区分相同名字的类

2.当类很多的时候，可以很好地管理类

3.控制访问范围

### 包的基本语法

```java
1.package 关键字
2. com.xxxx 表示包名
```

### 包的本质分析

> 包的本质就是创建不同的文件夹和目录来保存类文件

### 包的命名

> 只能包含数字，下划线，小圆点，但不能用数字开头，也不能是关键字和保留字

命名规范：

`com.xxxx.usr` 用户模块

`com.xxxx.utils` 工具模块

域名反着写，最后加上模块名

### 常用的包

![image-20221209184119352](https://blog.meowrain.cn/api/i/2022/12/10/3zkt3u-3.png)

### 引入包

语法：`import 包名.类名`

案例：

```java
package cn.meowrain.Object_.package_;

import java.util.Scanner;

public class package_01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        System.out.println(a);
    }
}
```

## 访问修饰符

![image-20221209194630958](https://blog.meowrain.cn/api/i/2022/12/10/5q5tda-3.png)

![image-20221209194636928](https://blog.meowrain.cn/api/i/2022/12/10/5q78mr-3.png)

![image-20221209194754093](https://blog.meowrain.cn/api/i/2022/12/10/5qw5s4-3.png)

## 封装

### 封装介绍

封装就是把抽象出的数据[属性]和对数据的操作**[方法]**封装在一起，数据被保护在内部，程序的其它部分只有通过被授权的操作**[方法]**，才能对数据进行操作

### 封装的理解和好处

1. 隐藏实现细节
2. 可以对数据进行验证，保证安全合理

## 封装实现的步骤

- 将属性进行私有化（不能直接修改属性）
- 提供一个公共的(public)set方法，用于对属性判断并赋值

  - ```java
    public void setXXX(类型 参数名) {
    // XXX表示某个属性
        //加入数据验证的业务逻辑
        属性 = 参数名;
    }
    ```
- 提供一个公共的(public)get方法，用于获取属性的值

  - ```java
    public 数据类型 getXXX(){
        //权限判断，xxx某个属性
        return xxx;
    }
    ```

### 快速入门案例

![image-20221118101742062](https://blog.meowrain.cn/api/i/2022/11/18/u1yi7u-3.png)

```java
package cn.meowrain.Encap_;

public class encap_01 {

    public static void main(String[] args) {
        Person person = new Person();
        person.setName("meowrainyyds");
        person.setAge(-1);
    }
}
class Person
{
    public String name;
    private int age;
    private double salary;
    private String job;
    public void setName(String name) {
        if(name.length()>=6||name.length()<=2){
            System.out.println("名字的长度错误，长度需要在2-6之间");

        }else {
            this.name = name;
        }
    }
    public void setAge(int age) {
        if(age<=1||age>=120){
            System.out.println("输入年龄错误(1-120)");
        }else {
            this.age = age;
        }

    }
    public void setSalary(double salary) {
        this.salary = salary;
    }
    public void setJob(String job) {
        this.job = job;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public double getSalary() {
        return salary;
    }
    public String getJob() {
        return job;
    }
    public void getInfo() {
        System.out.println(name + " " + "is" + age + "years old");
    }
  
}
```

![image-20221209200402253](https://blog.meowrain.cn/api/i/2022/12/10/6oa8gj-3.png)

### 把构造器和封装结合

在构造器中添加

```java
        setName(name);
        setAge(age);
```

即可实现构造的时候调用这两个函数，从而判断输入的数据是否符合要求，然后使用这两个函数进行赋值

```java
package cn.meowrain.Encap_;

public class encap_01 {

    public static void main(String[] args) {
        Person person = new Person("meowrainyyds", -1);
        person.getInfo();
    }
}

class Person {
    public String name;
    private int age;
    private double salary;
    private String job;

    public Person(String name, int age) {
        setName(name);
        setAge(age);
    }

    public void setName(String name) {
        if (name.length() >= 6 || name.length() <= 2) {
            System.out.println("名字的长度错误，长度需要在2-6之间");

        } else {
            this.name = name;
        }
    }

    public void setAge(int age) {
        if (age <= 1 || age >= 120) {
            System.out.println("输入年龄错误(1-120)");
        } else {
            this.age = age;
        }

    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void setJob(String job) {
        this.job = job;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public double getSalary() {
        return salary;
    }

    public String getJob() {
        return job;
    }

    public void getInfo() {
        System.out.println(name + " " + "is" + age + "years old");
    }

}
```

### 课堂练习

![image-20221118113154656](https://blog.meowrain.cn/api/i/2022/11/18/vxwxwt-3.png)

```java
package cn.meowrain.Encap_;

public class encap_02 {

}

class Account {
    String name;
    int balance;

    public Account(String name, int balance) {
        setName(name);
        setBalance(balance);
    }

    public void setName(String name) {
        if (name.length() >= 2 && name.length() <= 4) {
            this.name = name;
        }else{
            System.out.println("名字长度在2-4位之间，你输入的名字不合法");
        }
    }

    public void setBalance(int balance) {
        if(balance>20){
            this.balance = balance;
        }else {
            System.out.println("余额必须大于20");
        }
    }
public void getInfo(){
    System.out.println(name + " " + balance);
}
}

class AccountTest {
    public static void main(String[] args) {
    Account account = new Account("meowrain", 24);
    account.getInfo();
    }
}
```

## 继承

### 为什么需要继承

![](https://blog.meowrain.cn/api/i/2022/12/10/8eozay-3.png)

### 继承的基本介绍和示意图

![](https://blog.meowrain.cn/api/i/2022/12/10/8f3jcg-3.png)

### 继承的基本语法

```java
class 子类 extends 父类{

}
```

> 1.子类就会自动拥有父类定义的属性和方法
> 2.父类又叫超类和基类
> 3.子类又叫做派生类

### 快速入门案例

```java
package cn.meowrain.extends_;

public class extends_01 {
    public static void main(String[] args) {
        Student student = new Student("mike", 17, 100);
        student.eat(); //mike is eating
    }
}
class Human {
    String name;
    int age;
    public Human(String name, int age) {
        this.name = name;
        this.age = age;
    }
    //下面这个eat方法是共有的方法
    public void eat(){
        System.out.println(name + " is " + "eating");
    }
}
class Student extends Human {
    //Student继承了父类Human的所有属性
    double grades;
    public Student(String name, int age, double grades) {
        super(name, age);//构造器要使用super
        this.grades = grades;
    }
}
```

### 继承给编程带来的便利

1. 复用性增强
2. 代码的扩展性和维护性提高

### 细节问题

1. 子类继承了所有的属性和方法，非私有的属性和方法可以在子类直接访问，要通过父类提供公共的方法去访问
2. 子类必须调用父类的构造器，完成父类的初始化
3. 当创建子类对象时，不管使用子类的哪个构造器，默认情况下总会去调用父类的无参构造器，如果父类没有提供无参构造器，则必须在子类的构造器中用`super`去指定使用父类的哪个构造器完成对父类的初始化工作，否则编译不会通过
4. 如果希望指定去调用父类的某个构造器，则显式地调用一下：`super(参数列表)`
5. `super`在使用时，必须放在构造器第一行（**super**只能在构造器中使用）
6. `super()`和`this()`都只能放在构造器的第一行，因此这两个方法不能共存在一个构造器

> super（参数）：调用父类中的某一个构造函数（应该为构造函数中的第一条语句）。
> this（参数）：调用本类中另一种形式的构造函数（应该为构造函数中的第一条语句）。

7. java所有类都是 **Object类**的子类，**Object类**是所有类的基类
8. 父类构造器的调用不限于直接父类，将一直往上追溯直到 **Object**类
9. 子类最多只能继承一个父类
10. 不能滥用继承，子类和父类之间必须满足`is-a`的逻辑关系

---

```java
package cn.meowrain.extends_;

public class extends_02 {

}

class Base {
    int n1;
    int n2;
    String name;

    public Base() {
    }// 无参构造器

    public Base(int n1) {
        this.n1 = n1;
    }

    public Base(int n1, int n2) {
        this.n1 = n1;
        this.n2 = n2;
    }

    public Base(int n1, int n2, String name) {
        this(n1, n2);
        /*
         * 这个this(n1,n2);
         * 相当于调用上面的
            this.n1 = n1;
            this.n2 = n2;
        */
        this.name = name;
    }
}

class kids extends Base {
    int age;
    public kids(int n1,int n2,int age){
        super(n1,n2);
        /*  super(n1,n2);
         * 相当于 
         *        this.n1 = n1;
                  this.n2 = n2;
         */
        this.age = age;
    }
}
class adult extends Base {
    public adult(int n1,int n2,String name){
        super(n1,n2,name);
    }
}
class little_kids extends kids {
    String love;
    public little_kids(int n1,int n2,int age,String love){
        super(n1,n2,age);
        this.love = love;
    }
}
```

### 继承的本质分析

> 看下面这些代码

```java
package com.hspedu.extend_;

/**
 * 讲解继承的本质
 */
public class ExtendsTheory {
    public static void main(String[] args) {
        Son son = new Son();// 内存的布局
        // ?-> 这时请大家注意，要按照查找关系来返回信息
        // (1) 首先看子类是否有该属性
        // (2) 如果子类有这个属性，并且可以访问，则返回信息
        // (3) 如果子类没有这个属性，就看父类有没有这个属性(如果父类有该属性，并且可以访问，就返回信息..)
        // (4) 如果父类没有就按照(3)的规则，继续找上级父类，直到 Object...
        // System.out.println(son.name);//返回就是大头儿子
        // System.out.println(son.age);//返回的就是 39
        // System.out.println(son.getAge());//返回的就是 39
        System.out.println(son.hobby);// 返回的就是旅游
    }
}

class GrandPa { // 爷类
    String name = "大头爷爷";
    String hobby = "旅游";
}

class Father extends GrandPa {// 父类
    String name = "大头爸爸";
    private int age = 39;

    public int getAge() {
        return age;
    }
}

class Son extends Father { // 子类
    String name = "大头儿子";
}
```

> **子类创建的内存布局**
> ![](https://blog.meowrain.cn/api/i/2022/12/10/aes0io-3.png)

### 练习

![](https://blog.meowrain.cn/api/i/2022/12/10/ajhkeh-3.png)

> 会输出
> a
> b name
> b

**分析：B类无参构造器中，其实第一句是隐藏的`super()`，所以会先执行A类的无参构造器，输出a，然后执行`this("abc")`，调用B类本类下的有参构造器，输出`b name`，接着执行`System.out.println("b")`，输出b**

---

> 编写 Computer 类，包含 CPU、内存、硬盘等属性，getDetails 方法用于返回 Computer 的详细信息
> 编写 PC 子类，继承 Computer 类，添加特有属性【品牌 brand】
> 编写 NotePad 子类，继承 Computer 类，添加特有属性【color】
> 编写 Test 类，在 main 方法中创建 PC 和 NotePad 对象，分别给对象中特有的属性赋值，以及从 Computer 类继承的属性赋值，并使用方法并打印输出信息

```java
package cn.meowrain.extends_;

class Test {
    public static void main(String[] args) {
        PC pc = new PC("i5", 16, 512, "Lenovo");
        Notepad notepad = new Notepad("j1900", 8, 64, "white");
        pc.getDetails();
        notepad.getDetails();
    }
}

public class Computer {
    String brand;
    String cpu;
    int memory;
    int disk_size;

    public Computer(String cpu, int memory, int disk_size) {
        this.cpu = cpu;
        this.memory = memory;
        this.disk_size = disk_size;
    }

    public void getDetails() {
        System.out.println("the computer's" + " " + "cpu is " + cpu + " " + "the memory size is " + memory + " " + "the disk size is" + " " + disk_size);
    }
}

class PC extends Computer {
    String brand;

    public PC(String cpu, int memory, int disk_size, String brand) {
        super(cpu, memory, disk_size);
        this.brand = brand;
    }

    public void getDetails() {
        System.out.println("the computer's brand is" + brand + " " + "cpu is " + cpu + " " + "the memory size is " + memory + " " + "the disk size is" + " " + disk_size);
    }
}

class Notepad extends Computer {
    String color;

    public Notepad(String cpu, int memory, int disk_size, String color) {
        super(cpu, memory, disk_size);
        this.color = color;
    }

    public void getDetails() {
        System.out.println("the computer's color is" + color + " " + "cpu is " + cpu + " " + "the memory size is " + memory + " " + "the disk size is" + " " + disk_size);
    }
}
```

## super关键字
### 基本介绍
>   `super`代表父类的引用，用于**访问父类的属性，方法和构造器**

### 基本语法
1. 访问父类的属性，但是不能访问父类的 **private**属性
    使用：`super.属性名`
2. 访问父类的方法，不能访问父类的private方法
    使用：`super.方法名(参数列表)`
3. 访问父类的构造器
   使用：`super(参数列表)`
   只能放在构造器的第一句，只能出现一句

案例：
```java
package cn.meowrain.extends_;

public class super_ {
    public static void main(String[] args) {
        Child_01 child = new Child_01();
        child.getRes();
    }
}
class Base_01 {
    public String name = "mike";
    private int age = 8;
    public int getSum(int a,int b) {
        return a+b;
    }
}
class Child_01 extends Base_01 {
    public String name = super.name;//把父类的name属性的值赋值给自雷的name属性
    // public int age = super.age; 报错
    public void getRes(){
        System.out.println(super.getSum(19, 20));//调用并且输出父类中getSum方法的返回值
    }
}
```
### super给编程带来的便利
![](https://blog.meowrain.cn/api/i/2022/12/11/5vpim6-3.png)

### super和this的比较

![](https://blog.meowrain.cn/api/i/2022/12/11/5w5d9r-3.png)


## 方法重写（Override）
### 基本介绍
方法重写就是子类有一个方法，和父类的某个方法的名称，返回类型，参数一样，那么我们就说子类的这个方法覆盖了父类的方法

### 快速入门
```java
package cn.meowrain.extends_;

public class override_ {
    public static void main(String[] args) {
        Child_02 child_02 = new Child_02();
        child_02.getInfo();
    }
}

class Base_02 {
    public void getInfo() {
        System.out.println("hello my friends");
    }
}

class Child_02 extends Base_02 {
    @Override
    public void getInfo() {
        System.out.println("hello my good friends");
    }
}
```
### 注意项
> 子类方法不能缩小父类方法的访问权限
> 子类方法的形参列表，方法名称，要和父类方法的形参列表，方法名称完全一样
> 子类方法的返回类型和父类方法的返回类型要一样，或者是父类返回类型的子类，比如：`父类返回类型是Object，子类方法返回的类型是String`

### 方法重写和重载的区别
重载是 https://meowrain.cn/archives/java-mian-xiang-dui-xiang-ji-chu--chu-ji-
中的内容，回顾清看上面链接的内容
![](https://blog.meowrain.cn/api/i/2022/12/11/6szuyj-3.png)

## 多态
### 基本介绍
方法或对象具有多种形态，是面向对象的第三大特征，多态是建立在封装和继承基础上的
![](https://blog.meowrain.cn/api/i/2022/12/11/779d3z-3.png)
### 多态存在的三个必要条件
- 继承
- 重写
- 父类引用指向子类对象：`Parent p = new Child();`
### 多态的具体体现
#### 方法的多态
![](https://blog.meowrain.cn/api/i/2022/12/11/7a5tpq-3.png)
上图代码实现：
Shap.java
```java
package cn.meowrain.Poly;

public class Shape {
    public void draw(){
        System.out.println("画图形");
    }
}

```
Circle.java
```java
package cn.meowrain.Poly;

public class Circle extends Shape{
    public void draw(){
        System.out.println("画圆形");
    }
}

```

Square.java
```java
package cn.meowrain.Poly;

public class Square extends Shape{
    public void draw(){
        System.out.println("画方形");
    }
}

```

Triangle.java
```java
package cn.meowrain.Poly;

public class Triangle extends Shape{
    public void draw(){
        System.out.println("画三角形");
    }
}

```

Runner.java
```java
package cn.meowrain.Poly;

public class Runner {
    public static void main(String[] args) {
        Shape circle = new Circle();
        circle.draw();
        Shape triangle = new Triangle();
        triangle.draw();
        Shape square = new Square();
        square.draw();    
    }
}


```
> 注意：
> 1.一个对象的编译类型和运行类型可以不一致
> 2.编译类型在定义对象时就确定了，不能改变
> 3.运行类型是可以变化的
> 4.编译类型看定义时候=号的左边，运行类型看=号的右边
---

### 多态注意事项和细节讨论
> 多态的前提是： 两个对象（类）存在继承关系


#### 多态的向上转型
1. 本质：父类的引用指向了子类的对象
2. 语法：==父类类型 引用名 = new 子类类型();==
3. 特点：**编译类型看左边，运行类型看右边**
    可以调用父类中的所有成员（需遵守访问权限）
    不能调用子类中的特有成员-->只能调用子类和父类共有的成员
    最终运行效果看子类的具体实现

#### 多态的向下转型
1. 语法： ==子类类型 引用名 = (子类类型)父类引用;==
2. 只能强制转父类的引用，不能强转父类的对象
3. 要求父类的引用必须指向的是当前目标类型的对象
4. 当向下转型后，可以调用子类类型中所有成员

案例演示:
**Animal.java**
```java
package cn.meowrain.Poly.poly02;

public class Animal {
    String name = "动物";
    int age = 10;
    public void sleeper() {
        System.out.println("睡");
    }
    public void run() {
        System.out.println("跑");
    }
    public void eat(){
        System.out.println("吃");
    }
    public void show() {
        System.out.println("hello 你好");
    }
}
```

**Cat.java**
```java
package cn.meowrain.Poly.poly02;

public class Cat extends Animal{
    public void eat(){ //方法重写
        System.out.println("猫吃鱼");
    }
    public void catchMouse() {//cat特有方法
        System.out.println("猫抓老鼠");
    }
    
}
```

**PolyDetail.java**
```java
package cn.meowrain.Poly.poly02;

public class PolyDetail {
    public static void main(String[] args) {
        //向上转型,父类的引用指向了子类的对象
        Animal animal = new Cat();
        //animal.catchMouse() 错误,只能调用共同的属性
        //因为在编译阶段,能调用哪些成员,是由编译类型决定的
        //最终运行效果看运行类型的具体实现
        animal.eat();
        animal.run();
        animal.show();
        animal.sleeper();
        //如果想调用Cat的catchMouse方法
        //多态的向下转型
        //子类类型 引用名 = (子类类型)父类引用
        Cat cat = (Cat)animal;
        cat.catchMouse();
    }
}
```

---
> 注意: 属性没有重写只说!
> 属性的值看编译类型,也就是左侧
> 看下面的代码:
```java
package cn.meowrain.Poly.poly03;

public class item {

    public static void main(String[] args) {
        Base base = new Sub();
        //属性的值看编译类型
        System.out.println(base.count);//120
    }
}
class Base {//父类
    int count = 120;
}
class Sub extends Base { //子类
    int count = 234;
}
```

#### instanceOf比较操作符
> 介绍: **instanceOf**比较操作符,用于判断对象的运行类型是否为XX类型的子类型
举个例子:
```java
package cn.meowrain.Poly.poly03;

public class PolyDetail03 {
    public static void main(String[] args) {
        BB bb = new BB(); //运行类型是BB
        System.out.println(bb instanceof BB); //true
        System.out.println(bb instanceof AA); //true
        //向上转型
        //AA是编译类型,BB是运行类型
        AA aa = new BB();//运行类型是BB
        System.out.println(aa instanceof AA); //true
        System.out.println(aa instanceof BB);// true
        //向下转型
        BB ab = (BB)aa;//运行类型是BB
        System.out.println(ab instanceof AA); //true
        System.out.println(ab instanceof BB); //true
        AA am = new AA(); //运行类型是AA
        System.out.println(am instanceof AA);// true
        System.out.println(am instanceof BB); //false
    }
}
class AA {
}
class BB extends AA {

}

```

## java的动态绑定
> 1. 当调用对象方法的的时候，该方法回和该都西昂的内存地址/运行类型绑定
> 2. 当调用对象属性时，没有动态绑定机制，哪里声明，哪里使用

#### 在向上转型情况下的动态绑定示例
父类方法，对象类型：class cn.meowrain.bind.Son
```java
package cn.meowrain.bind;

public class bind01 {
    public static void main(String[] args) {
        Father sample = new Son();//向上转型
        sample.method();
    }
}

class Father {
    public void method(){
        System.out.println("父类方法，对象类型：" + this.getClass());
    }
}
class Son extends Father {

}
```
> 声明的是父类的引用，但是调用了子类对象，调用method，子类中没有这个方法，就去父类中去找，然后进行调用

---

接下来我们修改子类，在子类中重写`method`方法
```java
package cn.meowrain.bind;

public class bind01 {
    public static void main(String[] args) {
        Father sample = new Son();//向上转型
        sample.method();
    }
}

class Father {
    public void method(){
        System.out.println("父类方法，对象类型：" + this.getClass());
    }
}
class Son extends Father {
    @Override
    public void method() {
        System.out.println("子类方法，对象类型： " +this.getClass());
    }
}
```
> 子类方法，对象类型： class cn.meowrain.bind.Son
> 掉用子类对象，子类中含有`method`方法，所以调用子类中的这个method方法


---
注意： 下面说到的不属于动态绑定
运行时（动态）绑定针对的范畴只是对象的方法。
接下来我们来看一看属性绑定
```java
package cn.meowrain.bind;

public class bind01 {
    public static void main(String[] args) {
        Father sample = new Son();//向上转型
        System.out.println(sample.name);
    }
}

class Father {
    String name = "父类属性";

}
class Son extends Father {
    String name = "子类属性";
}
```
> 运行结果： 父类属性
从上面我们可以看出，输出是由编译类型决定的

### 多态的应用
#### 多态数组
> 数组的定义类型是父类类型，里面保存的实际元素类型为子类类型
应用实例：： 现有一个结构如下，要求创建1个Person对象，2个Student对象和2个Teacher对象，统一放在数组中，并调用每个对象的say方法
```java
package cn.meowrain.bind;

public class bind02 {
    public static void main(String[] args) {
        Person[] persons = new Person[5];
        persons[0] = new Person("jack", 20);
        persons[1] = new Student("mike", 18, 100);
        persons[2] = new Student("meowrain", 19, 150);
        persons[3] = new Teacher("gac", 24, 110);
        persons[4] = new Teacher("jjj", 25, 123);
        // persons[i]编译类型是Person，运行类型是根据实际情况通过JVM判断的

        for (int i = 0; i < persons.length; i++) {
            System.out.println(persons[i].say());// 动态绑定机制
            if (persons[i] instanceof Student) {
                Student student = (Student) persons[i];//向下转型
                student.study();
                //可以用下面这个替代
                // ((Student)persons[i]).study();
            } else if (persons[i] instanceof Teacher) {
                Teacher teacher = (Teacher) persons[i];//向下转型
                teacher.teach();
                //可以用下面这个替代
                // ((Teacher)persons[i]).teach();
            }
        }

    }
}

class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String say() {
        return "Perosn " + getName() + " is " + getAge() + "years old";
    }

}

class Student extends Person {
    private int score;

    public Student(String name, int age, int score) {
        super(name, age);
        this.score = score;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }

    @Override
    public String say() {
        return "Student " + getName() + " " + "is" + " " + "learning" + " " + "his score is " + getScore();
    }

    public void study() {
        System.out.println("student " + getName() + "is learning");
    }

}

class Teacher extends Person {
    private double salary;

    public Teacher(String name, int age, double salary) {
        super(name, age);
        this.salary = salary;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    @Override
    public String say() {
        return "Teacher " + getName() + "is teaching" + " " + "his salary is " + getSalary();
    }

    public void teach() {
        System.out.println("Teacher " + getName() + "is teaching");
    }
}
```

#### 多态参数
> 方法定义的形参类型为父类类型，实参类型允许为子类类型
> 
定义员工类Employee,包含姓名和月工资（private)，以及计算年工资getAnnual的方法，普通员工和经理继承了员工，经理类多了奖金bonus和管理manage方法，普通员工多了work方法，普通员工和经理类要求分别重写getAnnual方法
测试类中添加一个方法showEmpAnnual(Employee e),实现获取任何员工对象的年工资，并在main方法中调用该方法[e.getAnnual]

测试类中添加一个方法，testWork,如果是普通员工，就调用那个work方法。如果是经理，就调用manage方法

Test.java
```java
package cn.meowrain.Poly.poly04;

public class Test {
    public double showEmpAnnual(Employee e) {
        return e.getAnnual();
    }
    public void testWork(Employee e){
        if(e instanceof NormalEmployee){
            ((NormalEmployee)e).work();
        }else if (e instanceof Manager){
            ((Manager)e).manage();
        }

    }
    public static void main(String[] args) {
        NormalEmployee worker = new NormalEmployee("mike", 4000);
        Manager manager = new Manager("john", 4300, 5000);
        Test test = new Test();
        System.out.println("管理者工资： " + test.showEmpAnnual(manager));
        System.out.println("工人工资： " + test.showEmpAnnual(worker));
        test.testWork(manager);
        test.testWork(worker);
    }
}

```

Employee.java
```java
package cn.meowrain.Poly.poly04;

public class Employee {
    private String name;
    private double salary;
    
    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public double getAnnual () {
        return salary*12;
    }
}


```

Manager.java
```java
package cn.meowrain.Poly.poly04;

public class Manager extends Employee{
    private double bonus;

    public Manager(String name, double salary, double bonus) {
        super(name, salary);
        this.bonus = bonus;
    }

    public double getBonus() {
        return bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }
    public void manage(){
        System.out.println("Manager " + getName() + " " + "is managing");
    }
    @Override
    public double getAnnual() {
        return (getSalary()*12 + bonus);
    }
    
    
}

```

NormalEmployee.java
```java
package cn.meowrain.Poly.poly04;

public class NormalEmployee extends Employee{

    public NormalEmployee(String name, double salary) {
        super(name, salary);
    }
    public void work(){
        System.out.println("普通工人" + " " + getName() + " " + "is working");
    }
    @Override
    public double getAnnual() {
        // TODO Auto-generated method stub
        return super.getAnnual();
    }
}

```

## Object类详解

### equals方法

== 是一个比较运算符

![image-20221121193757084](https://blog.meowrain.cn/api/i/2022/11/21/w1hxcz-3.png)

![image-20221121201430025](https://blog.meowrain.cn/api/i/2022/11/21/xb6e82-3.png)

> 在看下面这个东西之前，我们先抛出一个问题 
> **String属于什么数据类型？**
> https://zhuanlan.zhihu.com/p/136468277
> 引用类型
> 基本数据类型和引用数据类型详见[Java数据类型：基本数据类型和引用数据类型 (biancheng.net)](http://c.biancheng.net/view/5672.html)

区分

```java
package com.hsp.object;

public class Equals_exercise02 {
    public static void main(String[] args) {
        String name_1 = "hello";
        String name_2 = "hello";
        System.out.println(name_2 == name_1);//true
        /*
        * String str1 = "abcd"的实现过程：首先栈区创建str引用，
        * 然后在String池（独立于栈和堆而存在，存储不可变量）
        * 中寻找其指向的内容为"abcd"的对象，如果String池中没有，
        * 则创建一个，然后str指向String池中的对象，
        * 如果有，则直接将str1指向"abcd""；
        * 如果后来又定义了字符串变量 str2 = "abcd",
        * 则直接将str2引用指向String池中已经存在的“abcd”，
        * 不再重新创建对象；当str1进行了赋值（str1=“abc”），
        * 则str1将不再指向"abcd"，而是重新指String池中的"abc"，
        * 此时如果定义String str3 = "abc",进行str1 == str3操作，
        * 返回值为true，因为他们的值一样，地址一样，
        * 但是如果内容为"abc"的str1进行了字符串的+连接str1 = str1+"d"
        * ；此时str1指向的是在堆中新建的内容为"abcd"的对象，
        * 即此时进行str1==str2，返回值false，因为地址不一样。


	String str3 = new String("abcd")的实现过程：
*	 直接在堆中创建对象。
*	 如果后来又有
* 	 String str4 = new String("abcd")，str4不会指向之前的对象，
* 	 而是重新创建一个对象并指向它，
* 	 所以如果此时进行str3==str4返回值是false，
* 	 因为两个对象的地址不一样，如果是str3.equals(str4)，
* 	 返回true,因为内容相同。

        * */
        String name_3 = new String("hello");
        String name_4 = new String("hello");
        System.out.println(name_3 == name_4);//false
        System.out.println(name_3.equals(name_4));
        System.out.println(name_1.equals(name_2));
    }
}

```



### hashCode方法

1. 提高具有哈希结构的容器效率
2. 两个引用，如果指向的是同一个对象，则**哈希值**肯定是一样的
3. 两个引用，如果指向的是不同的对象，则**哈希值**是不一样的
4. 哈希值主要根据地址号来的，不能将**哈希值**等价于地址

```java
package com.hsp.object;

public class HashCode {
    public static void main(String[] args) {
        AA aa = new AA();
        AA aa2 = new AA();
        System.out.println(aa.hashCode());
        System.out.println(aa2.hashCode());
        /*460141958
          1163157884*/
    }
}
class AA {}

```



### toString方法

基本介绍：

默认返回： **`全类名 + @ + 哈希值的十六进制`**

子类往往重写toString方法，用于返回对象的属性信息

```java
package com.hsp.object;

public class toString {
    public static void main(String[] args) {
        Monster monster = new Monster("妖怪","保安",1000);
        System.out.println(monster.toString());//com.hsp.object.Monster@1b6d3586
    }
}
class Monster {
        private String name;
        private String job;
        private double sal;

    public Monster(String name, String job, double sal) {
        this.name = name;
        this.job = job;
        this.sal = sal;
    }
}
```

重写`toString方法`，打印对象或拼接对象时，都会自动调用该对象的toString形式

```java
package com.hsp.object;

public class toString {
    public static void main(String[] args) {
        Monster monster = new Monster("妖怪","保安",1000);
        System.out.println(monster.toString());//Monster{name='妖怪', job='保安', sal=1000.0}

    }
}
class Monster {
        private String name;
        private String job;
        private double sal;
//        重写toString方法

    @Override
    public String toString() {
        return "Monster{" +
                "name='" + name + '\'' +
                ", job='" + job + '\'' +
                ", sal=" + sal +
                '}';
    }

    public Monster(String name, String job, double sal) {
        this.name = name;
        this.job = job;
        this.sal = sal;
    }
}
```

当直接输出一个对象时候，`toString方法`会被默认的调用

```java
package com.hsp.object;

public class toString {
    public static void main(String[] args) {
        Monster monster = new Monster("妖怪", "保安", 1000);
        System.out.println(monster);
    }
}

class Monster {
    private String name;
    private String job;
    private double sal;
//        重写toString方法

    @Override
    public String toString() {
        return "Monster{" +
                "name='" + name + '\'' +
                ", job='" + job + '\'' +
                ", sal=" + sal +
                '}';
    }

    public Monster(String name, String job, double sal) {
        this.name = name;
        this.job = job;
        this.sal = sal;
    }
}
```

### finalize()

当垃圾回收器确定不存在对该对象的更多引用时，由对象的垃圾回收器调用此方法

1.当对象被回收时，系统自动调用该对象的finalize方法。子类可以重写该方法，做一些释放资源的操作

2.什么时候被回收：当某个对象没有任何引用的时候，则jvm就认为这个对象是一个垃圾对象，就会用垃圾回收机制来销毁该对象，在销毁该对象前，会先调用finalize方法

3.垃圾回收机制的调用，是由系统来决定，也可以由`System.gc()`主动触发垃圾回收机制

> <p style="color:red" >实际开发中基本不会运用，应付面试</p>

