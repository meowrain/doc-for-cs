---
title: Java面向对象(高级)
date: 2022-12-13 06:59:35.138
updated: 2022-12-14 07:55:36.969
url: https://meowrain.cn/archives/java-mian-xiang-dui-xiang--gao-ji-
categories: 
- 笔记
- Java
tags: 
- java
- OOP
---

# Java面向对象(高级)
## 类变量/类方法
[类变量/类方法-博客园](https://www.cnblogs.com/ffforward/p/15244615.html#:~:text=%E3%80%90%E7%B1%BB%E5%8F%98%E9%87%8F%E3%80%91%201%20%E4%BB%8B%E7%BB%8D%20%E7%B1%BB%E5%8F%98%E9%87%8F%EF%BC%88%E5%8F%88%E5%8F%AB%E9%9D%99%E6%80%81%E5%8F%98%E9%87%8F%EF%BC%89%E6%98%AF%E8%AF%A5%E7%B1%BB%E7%9A%84%E6%89%80%E6%9C%89%E5%AF%B9%E8%B1%A1%E5%85%B1%E4%BA%AB%E7%9A%84%E5%8F%98%E9%87%8F%EF%BC%8C%E4%BB%BB%E4%BD%95%E4%B8%80%E4%B8%AA%E8%AF%A5%E7%B1%BB%E7%9A%84%E5%AF%B9%E8%B1%A1%E5%8E%BB%E8%AE%BF%E9%97%AE%E5%AE%83%E6%97%B6%EF%BC%8C%E5%8F%96%E5%88%B0%E7%9A%84%E9%83%BD%E6%98%AF%E7%9B%B8%E5%90%8C%E7%9A%84%E5%80%BC%EF%BC%8C%E5%90%8C%E6%A0%B7%E4%BB%BB%E4%BD%95%E4%B8%80%E4%B8%AA%E8%AF%A5%E7%B1%BB%E7%9A%84%E5%AF%B9%E8%B1%A1%E5%8E%BB%E4%BF%AE%E6%94%B9%E5%AE%83%E6%97%B6%EF%BC%8C%E4%BF%AE%E6%94%B9%E7%9A%84%E4%B9%9F%E6%98%AF%E5%90%8C%E4%B8%80%E4%B8%AA%E5%8F%98%E9%87%8F%E3%80%82%20%E5%AE%9A%E4%B9%89%E7%B1%BB%E5%8F%98%E9%87%8F%EF%BC%9A%20%E8%AE%BF%E9%97%AE%E4%BF%AE%E9%A5%B0%E7%AC%A6%20static%20%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B,%E7%B1%BB%E5%8F%98%E9%87%8F%E7%9A%84%E8%AE%BF%E9%97%AE%20%E5%8F%AF%E4%BB%A5%E9%80%9A%E8%BF%87%20%E7%B1%BB%E5%90%8D.%E7%B1%BB%E5%8F%98%E9%87%8F%E5%90%8D%20%E6%88%96%E8%80%85%20%E5%AF%B9%E8%B1%A1%E5%90%8D.%E7%B1%BB%E5%8F%98%E9%87%8F%E5%90%8D%20%E6%9D%A5%E8%AE%BF%E9%97%AE%EF%BC%8C%E4%BD%86Java%E8%AE%BE%E8%AE%A1%E8%80%85%E6%8E%A8%E8%8D%90%E6%88%91%E4%BB%AC%E4%BD%BF%E7%94%A8%20%E7%B1%BB%E5%90%8D.%E7%B1%BB%E5%8F%98%E9%87%8F%E5%90%8D%20%E7%9A%84%E6%96%B9%E5%BC%8F%E6%9D%A5%E8%AE%BF%E9%97%AE%E3%80%82)
![](https://static.meowrain.cn/i/2022/12/13/a87en5-3.png)

### 类变量快速入门
#### 介绍
类变量（又叫静态变量）是该类的所有对象共享的变量，任何一个该类的对象去访问它时，取到的都是相同的值，同样任何一个该类的对象去修改它时，修改的也是同一个变量。
> `定义类变量：访问修饰符 static 数据类型 变量名; `
**静态变量是类加载的时候，就创建了,所以我们没有创建对象实例**
定义一个变量 count ,是一个类变量(静态变量) static 静态
该变量最大的特点就是会被Child 类的所有的对象实例共享
```java
package cn.meowrain.classVariable;

public class var01 {
    public static void main(String[] args) {
        Child child01 = new Child("mike");
        Child child02 = new Child("john");
        child01.count++;
        child02.count++;
        System.out.println("共有" + Child.count + "个小朋友参加了游戏");
    }
}
class Child {
    private String name;
    public static int count = 0;
    public Child(String name){
        this.name = name;
    }
    public void join() {
        System.out.println("小朋友" + name + "加入了游戏....");
    }
}
```
> 输出: 共有2个小朋友参加了游戏

#### 访问类变量
> 可以通过 `类名.类变量名` 或者 `对象名.类变量名` 来访问，但Java设计者推荐我们使用 类名.类变量名 的方式来访问。
```java
package cn.meowrain.classVariable;

public class var01 {
    public static void main(String[] args) {
        Child child01 = new Child("mike");
        Child child02 = new Child("john");
        child01.join();
        child02.join();
        System.out.println("共有" + Child.count + "个小朋友参加了游戏"); 
        //通过 对象名.类变量名 来访问
    }
}
class Child {
    private String name;
    public static int count = 0;
    public Child(String name){
        this.name = name;
    }
    public void join() {
        System.out.println("小朋友" + name + "加入了游戏....");
        count++;
    }
}
```

### 类方法
#### 介绍
类变量也叫静态变量。
`定义格式如下：访问修饰符 static 数据返回类型 方法名(){}`
#### 类方法经典使用场景
（1）当方法中不涉及到任何和对象相关的成员，则可以将方法设计成静态方法，提高开发效率。
（2）比如工具类中的方法 utils
Math类、Arrays类、Collections集合类
（3）在实际开发中，往往将一些通用的方法，设计成静态方法，这样我们不需要创建对象就可以使用，比如打印一维数组，冒泡排序等等

#### 类方法和普通方法的区别
1. 类方法中不允许使用和对象有关的关键字，
2. 比如this 和super。普通方法(成员方法)可以。
3. 类方法中，只能访问 静态变量 或 静态方法；而普通方法既可以访问普通变量（方法），也可以访问静态的。

#### 类方法可以重写吗？
1. 可以被继承，但是不能被重写，如果父子类静态方法名相同，则会隐藏derive类方法（调用base类的方法）
2. 静态方法是编译时绑定的，方法重写是运行时绑定的。
https://blog.csdn.net/m0_37974032/article/details/81157433


类方法的使用： 
使用：
如下：
```java
package cn.meowrain.classVariable;

public class var02 {
}

class Caculate {
    public static void main(String[] args) {
        int sum01 = sum(1, 2);
        int sum02 = sum(5, 10, 20);
        System.out.println(sum01 + " " + sum02);//3 35
    }

    public static int sum(int a, int b) {
        return a + b;
    }

    public static int sum(int a, int b, int c) {
        return a + b + c;
    }
}
```

## 理解main方法
直接看下面这个文章就行了，写得很不错
https://www.cnblogs.com/ffforward/p/15253293.html

## Java代码块
#### 基本介绍
代码块又称为初始化块，属于类中的成员，类似于方法，把逻辑语句封装在方法体中，通过{}包围起来
**其在创建对象时隐式调用**
#### 基本语法
<pre style="color: blue">
<code>
[修饰符]{
    代码
}
</code>
</pre>

说明： 
(1) 修饰符可选，要写的话，也只能写static

(2) 代码块分为两类，使用static修饰的叫**静态代码块**，没有static修饰的，叫**普通代码块**

(3) 逻辑语句可以为任何逻辑语句（输入、输出、方法调用、循环、判断等

(4) 分号；可以写上，也可以省略

#### 代码块的好处
（1）相当于另外一种形式的构造器（对构造器的补充机制），可以做初始化的操作。

（2）如果多个构造器中都有重复的语句，可以抽取到初始化块中，提高代码的复用性


**实际使用：**

如下，我们的三个构造器中都含有`System.out.println("Welcome to Code World!");`，这使得代码很冗杂，使用代码块，就能让这个代码更好看一些，代码块会在每次类创建时调用

```java
package cn.meowrain.codeBlock;

public class code01 {
    public static void main(String[] args) {
        code01_child child01 = new code01_child("mike");
        code01_child child02 = new code01_child("meme", 15);
        code01_child child03 = new code01_child("meow", 18, "bear");
    }
}

class code01_child {
    String name;
    int age;
    String love;
    public code01_child(String name) {
        this.name = name;
        System.out.println("Welcome to Code World!");
        System.out.println("hello " + name);
    }
    public code01_child(String name, int age) {
        this.name = name;
        this.age = age;
        System.out.println("Welcome to Code World!");
        System.out.println("hello " + name);
    }
    public code01_child(String name,int age,String love) {
        this.name = name;
        this.love = love;
        this.age = age;
        System.out.println("Welcome to Code World!");
        System.out.println("hello " + name);
    }
    
}
```

·············修改版···················
```java
package cn.meowrain.codeBlock;

public class code01 {
    public static void main(String[] args) {
        code01_child child01 = new code01_child("mike");
        code01_child child02 = new code01_child("meme", 15);
        code01_child child03 = new code01_child("meow", 18, "bear");
    }
}

class code01_child {
    String name;
    int age;
    String love;
    {
        System.out.println("Welcome to Code World!");
    }
    public code01_child(String name) {
        this.name = name;

        System.out.println("hello " + name);
    }
    public code01_child(String name, int age) {
        this.name = name;
        this.age = age;

        System.out.println("hello " + name);
    }
    public code01_child(String name,int age,String love) {
        this.name = name;
        this.love = love;
        this.age = age;

        System.out.println("hello " + name);
    }
    
}
```
输出结果：
```bash
Welcome to Code World!
hello mike
Welcome to Code World!
hello meme
Welcome to Code World!
hello meow
```


#### static 代码块
static代码块也叫静态代码块，作用就是对类进行初始化，而且它随着类的加载而执行，并且只会执行一次。

实际使用： 
```java
package cn.meowrain.codeBlock;

public class code01 {
    public static void main(String[] args) {
        code01_child child01 = new code01_child("mike");
        code01_child child02 = new code01_child("meme", 15);
        code01_child child03 = new code01_child("meow", 18, "bear");
    }
}

class code01_child {
    String name;
    int age;
    String love;
    static{
        System.out.println("Welcome to Code World!");
    }
    public code01_child(String name) {
        this.name = name;

        System.out.println("hello " + name);
    }
    public code01_child(String name, int age) {
        this.name = name;
        this.age = age;

        System.out.println("hello " + name);
    }
    public code01_child(String name,int age,String love) {
        this.name = name;
        this.love = love;
        this.age = age;

        System.out.println("hello " + name);
    }
    
}
```

输出结果：
>因为静态代码块只执行一次，所以只输出一次 `Welcome to Code World!`
```bash
Welcome to Code World!
hello mike
hello meme
hello meow
```

### 代码块使用注意事项
1. static代码块也叫静态代码块，作用就是对类进行初始化，而且它随着**类的加载而执行，只会执行一次**。如果是普通代码块，每创建一个对象，就执行一次。可以看上面的代码和运行结果
2. 类什么时候被加载？
   1. 创建对象实例 new 的时候
   2. 创建子类对象实例，父类也会被加载
   3. 使用类的静态成员时（静态属性，静态方法）
        ```java
        package cn.meowrain.codeBlock;

        public class code02 {
            public static void main(String[] args) {
                int c = A.sum(109, 10);
            }
        }

        class A {
            static{
                System.out.println("hello");
            }
            public static int sum(int a,int b){
                return a+b;
            }
        }
        class B extends A{

        }
        ```
        > 运行结果： hello
        由上可见,静态代码块会在类加载的时候执行
3. 普通的代码块，在创建对象实例（new的时候），会被隐式调用，如果只是单纯使用类中的静态变量，普通代码块不会被执行
    ```java
    package cn.meowrain.codeBlock;

    public class code02 {
        public static void main(String[] args) {
            int c = A.sum(109, 10);
            
        }
    }

    class A {
        {
            System.out.println("hello");
        }
        static int a = 10;
        public static int sum(int a, int b) {
            return a + b;
        }

    }

    class B extends A {

    }
    ```
   输出结果： 无
4. 创建一个对象的时候，在一个类的调用顺序是:
   - 调用静态代码块和静态属性初始化，按照顺序调用
   - 调用普通代码块和普通属性的初始化，按照顺序调用
   - 调用构造方法
    ```java
    package cn.meowrain.codeBlock;

    public class code03 {
        public static void main(String[] args) {
            AB ab = new AB();
            
        }
    }
    class AB {
        static {
            System.out.println("静态代码块初始化");
        }
        static int a = getN1();
        public static int getN1(){
            System.out.println("静态方法getN1初始化");
            return 100;
        }
        int c = getN2();
        public int getN2() {
            System.out.println("普通方法getN2初始化");
            return 200;
        }
        public AB(){
            System.out.println("构造器被调用");
        }
    }
    ```

> 运行结果如下
> 静态代码块初始化
> 静态方法getN1初始化
> 普通方法getN2初始化
> 构造器被调用     

## 单例设计模式
参考https://www.cnblogs.com/ffforward/p/15259948.html
### 介绍：
单例设计模式，就是采取一定的方法保证在整个的软件系统中，对某个类只能存在一个对象实例，并且该类只提供一个取得其对象实例的方法
> 单例模式有两种： 
> 1. 饿汉式
> 2. 懒汉式

### 实现方式
- 构造器私有化
- 类的内部创建对象
- 向外暴露一个静态的公共方法

### 饿汉式
> 类加载的时候实例化，并且创建单例对象
> 1. 构造器私有化
> 2. 在类的内部直接创建对象，该对象为static
> 3. 提供一个公共的static方法，返回这个对象
```java
package cn.meowrain.singlecasemode;
class test {
    public static void main(String[] args) {
        Hungry hungry = Hungry.getInstance();
        System.out.println(hungry.name);

    }
}
public class Hungry {
    public String name;
    private Hungry(String name){
        this.name = name;
    } //构造器私有化
    private static Hungry hungry = new Hungry("hello");
    public static Hungry getInstance(){
        return hungry;
    }
}

```

### 懒汉式
> 懒汉式： 默认不会实例化，什么时候用什么时候new
> 1. 构造器私有化
> 2. 定义一个static静态属性对象
> 3. 提供一个public的static方法，可以返回一个该类对象
> 4. 懒汉式，只有当用户使用getInstance时，才返回对象，后面再次调用时，会返回上次创建的该类对象，从而保证单例
```java
package cn.meowrain.singlecasemode;
class test02 {
    public static void main(String[] args) {
        Lazy lazy = Lazy.getInstanceOf();
        System.out.println(lazy.name);
    }
}
public class Lazy {
    public String name;
    private Lazy(String name){
        this.name = name;
    }
    private static Lazy lazy = null;
    public static Lazy getInstanceOf(){
        if(lazy==null){
            lazy = new Lazy("mmm");
        }
        return lazy;
    }

}
```
### 饿汉式和懒汉式的区别
（1）二者最主要的区别在于创建对象的时机不同：
饿汉式是在类加载时就创建了对象实例，
而懒汉式是在使用时才创建。

（2）饿汉式不存在线程安全问题，懒汉式存在线程安全问题。

（3）饿汉式存在浪费资源的可能（没有使用到这个对象实例），而懒汉式不存在这个问题。

（4）在javaSE标准类中，java.lang.Runtime就是经典的单例模式。

## final关键字
### 基本介绍：
final可以修饰类，属性，方法和局部变量
使用环境：
<pre style="color:red">
<code>
1. 当不希望类被继承时，可以用final修饰
2. 当不希望父类的某个方法被子类覆盖/重写时，可以用final关键字修饰
3. 当不希望类的某个属性的值被修改，可用final修饰
4. 当不希望某个局部变量被修改，可以用final修饰
</code>
</pre>
### final使用注意事项
> 1. final修饰的属性又叫常量
> 2. final修饰的属性在定义的时候，必须赋初值，并且以后不能再修改
> 3. 如果final修饰的属性是静态的，则初始化的位置只能是 1.定义时 2.在静态代码块中可以赋值，不能在构造器中赋值
> 4. final类不能继承，但是可以实例化对象
> 5. 如果类不是final类，但是有final方法，则该方法虽然不能重写，但可以被继承
> 6.final和static往往搭配使用，效率更高，不会导致类加载，底层编译器做了优化处理
> 7. 包装类(**Integer,Double,Float,Boolean等都是final**)，**String**也是final类


## 抽象类