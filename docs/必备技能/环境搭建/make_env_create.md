# Build the make environment on windows and Linux

# Intro Of Make
> Intro: When we write c++ programs,we always need to use commands such as `g++ xxx.cpp -g -std=c++17 -Wall -o xxx`,then we can compile our program and execute it.
> However,it is complicated,maybe waste mass of time.
> Then, make appears.

Since then,we can compile our program by execute `make` in our terminal,and then our program will be compile.

That's so cool! Isn't it?

![1692957848996](image/make_env_create/1692957848996.png)

> When you use make,the result is just like the image upon.

# How to create a Make Environment on windows?
Just click the [URL](https://sourceforge.net/projects/mingw-w64/files/) here.
And you will enter in a new website

![1692956984020](image/make_env_create/1692956984020.png)


Then click where the arrow points to.
![1692957035325](image/make_env_create/1692957035325.png)

![1692957082165](image/make_env_create/1692957082165.png)


After downloading over,move it to another place,you can create a directory like `env` to store your programming environment.
![1692957162890](image/make_env_create/1692957162890.png)

Then unzip it.Enter in the directory we unzip just now.
![1692957195631](image/make_env_create/1692957195631.png)

Then click bin directory.
![1692957211203](image/make_env_create/1692957211203.png)

Copy the path of it
![1692957256691](image/make_env_create/1692957256691.png)

Now we can use windows shortcuts:`windows + q`,
![1692957303013](image/make_env_create/1692957303013.png)

Then search env
![1692957344825](image/make_env_create/1692957344825.png)

![1692957368616](image/make_env_create/1692957368616.png)

![1692957409592](image/make_env_create/1692957409592.png)

![1692957476472](image/make_env_create/1692957476472.png)

Then we click "确定"


Did it work?Let's see!

Open the terminal:

Input `gcc -v` and see whether you have the words like the images below
![1692957543113](image/make_env_create/1692957543113.png)




> 😊Congratulations! Now we have successfully create gcc&g++ system environment variables.

😉However,make command still not work.Why?
It's because in mingw-w64,make program is not called make,but mingw32-make.What we need to do is just change the name of it.Then make works!

![1692957722305](image/make_env_create/1692957722305.png)

![1692957776679](image/make_env_create/1692957776679.png)


## How to create a Make Environment on Linux?

Use your package manager such as apt.

```sh
sudo apt-get install gcc g++ make
```

Then,then write your makefile,start your programming journey！

