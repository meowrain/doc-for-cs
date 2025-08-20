# 学习 GIT

### Git和Github的区别
> Git是一种分布式版本控制系统，用于管理代码或文本文件的版本控制。使用Git，您可以跟踪您或您的团队在软件开发过程中所做的更改，并可以在需要时回溯到以前的版本。Git还允许多个开发者协同工作，并在同一时间进行更改，最后将这些更改合并到一个主分支中。

> Github是一个基于Web的Git代码托管平台，它允许开发者共享和协作开发项目。Github的基本功能包括代码托管、版本控制、问题跟踪和协作工具等。Github上的开源项目非常多，这些项目都是由开发者共享的，其他人可以查看并参与进来。此外，Github还提供了许多用于集成、测试、构建和部署软件的工具和服务，这些工具和服务可以加快软件开发和交付过程。
### 使用图形化 Git

1. GitKraken

   > GitKraken 是一款炫酷且友好的 Git 客户端，支持跨平台使用，提供可视化的操作界面，适合初学者和高级用户使用。

2. Sourcetree

   > Sourcetree 是一款免费的 Git 和 Mercurial 客户端，支持跨平台使用，提供可视化的操作界面，适合初学者和高级用户使用。

3. TortoiseGit

> TortoiseGit 是一款免费的 Git 客户端，只支持 Windows 平台使用，提供可视化的操作界面和 Windows 资源管理器的集成，适合初学者使用。

4. GitHub Desktop

> GitHub Desktop 是一款免费的 Git 客户端，支持跨平台使用，提供可视化的操作界面和 GitHub 平台的集成，适合 GitHub 用户使用。

5. Git GUI（安装 Git 后自带）

> Git GUI 是 Git 自带的可视化操作界面，只支持命令行方式使用，适合高级用户使用。

### 学习 Git 命令

Git 文档：
- 官方文档: [https://git-scm.com/docs](https://git-scm.com/docs)
- 菜鸟教程：[https:/www.runoob.com/git/git-tutorial.html](https://www.runoob.com/git/git-tutorial.html)
- 猴子都能懂的 Git 入门：[https:/backlog.com/git-tutorial/cn/](https://backlog.com/git-tutorial/cn/)
- 廖雪峰的文档：[https:/www.liaoxuefeng.com/wiki/896043488029600/](https://www.liaoxuefeng.com/wiki/896043488029600)
- Git命令大全：[https:l/backlog.com/git-tutorial/,cn/reference/](https://backlog.com/git-tutorial/cn/reference/)

> 这里列出了一些优秀的在线 Git 教程，适合初学者和高级用户使用。其中，猴子都能懂的 Git 入门是一个非常好的入门教程，它提供了大量的实例和动画，可以帮助您快速上手 Git。菜鸟教程和廖雪峰的教程也是非常优秀的教程，提供了详细的讲解和实例，适合深入学习 Git。Git 简明指南则是一个非常简单的教程，可以在几分钟内看完，并用来复习 Git。无论您是初学者还是高级用户，这些在线 Git 教程都可以帮助您学习 Git 的基本知识和技能。


---

## 打不开 github ?

> 因为一些众所周知的原因，github 在国内经常上不去，就连 clone 代码都有时候会因为网络原因发生错误

### 热点法

大家可以打开手机热点，用电脑连接手机热点，这个时候 github 大多数时候就可以直接进去了，如果使用 wifi 就会出现一会儿能用，一会儿不能用的情况

### 更换 Hosts

> 什么是 Hosts?
> Hosts 文件是一个没有扩展名的操作系统文件，以表的形式存储了主机名和 IP 地址的映射关系[1]。Hosts 又称 host table，译为“主机表”。现代系统中，虽然 DNS 取代了主机表，但主机表的应用依旧很广[1]。和 DNS 不同的是，用户可以直接对 Hosts 文件进行控制。

那么怎么更换 hosts 呢？
[安装 SwitchHosts](https://cloud.tencent.com/developer/article/1408956)
大家看上面的这个文档看完安装就可以了，傻瓜式安装，我就不详细说了。我主要说一下配置这个东西

#### 配置 SwitchHosts

![](https://blog.meowrain.cn/api/i/2023/04/01/tywz3y-3.webp)

![](https://blog.meowrain.cn/api/i/2023/04/01/tz45k6-3.webp)

> 这是更新 url: https://code.meowrain.cn/https://github.com/521xueweihan/GitHub520/blob/main/hosts

![](https://blog.meowrain.cn/api/i/2023/04/01/tzoth0-3.webp)
直接填进去确定就行了
![](https://blog.meowrain.cn/api/i/2023/04/01/u07q8i-3.webp)

然后刷新本地 dns 缓存。
打开控制台，<kbd>Windows</kbd> + <kbd>R</kbd>，输入`powershell`
![](https://blog.meowrain.cn/api/i/2023/04/01/u0repf-3.webp)
回车打开，输入命令

```cmd
ipconfig /flushdns
```

![](https://blog.meowrain.cn/api/i/2023/04/01/u0xap3-3.webp)

## 开始使用 Github

在开始使用 github 之前，你应当了解并学习过[Git](/tools-learn/git-learn.md)

- Github 官方文档：https://docs.github.com/zh/get-started/quickstart/set-up-git
- OSChina 开源指北: https://oschina.gitee.io/opensource-guide/

  看上面的这个就行了，相信你会受益匪浅
## 参与开源项目

> 想在 github 参与别的开源项目，或者参与这个文档？
> 来看下面的文章：
> https://github.com/firstcontributions/first-contributions/blob/main/translations/README.zh-cn.md

## 想要书写酷酷的github个人主页？
>### 1.建仓
>在 GitHub 中创建一个与 GitHub ID 同名的仓库，例如我的 GitHub ID 为 lcekold，因此创建的仓库名也为 lcekold。：
>![这是图片](https://blog.meowrain.cn/api/i/2023/04/12/11a7349.webp)
>由于我已创建了这个仓库，所以 GitHub 会在下方提示我已经创建过同名的仓库了。  
>
>创建时记得勾选从下方的「Add a README file」，在仓库中添加一个 README 的 Markdown 文件，等会我们就是要在这个文件中创建我们最终想要的个人主页样式。  
>
>创建仓库之后，点击右上角的个人头像，选择「Your profile」回到你的 GitHub 主页，你应该就可以看到 Hi there 的文本内容。
>![这是图片](https://blog.meowrain.cn/api/i/2023/04/12/11cou7h.webp)
>点击右侧的编辑按钮，进入 REMDME 文件的编辑状态。
进入编辑状态，这个文档是使用 Markdown 语法来编辑的，如果你之前用过 Markdown 的话，编辑起来应该非常简单，如果你没接触过，想学的话十分钟也可以入门。
>
>只需要记住一点，上一行结束时，要在最末尾加多至少两个空格，才能实现换行，否则本来想分行的两行内容会连在一起。
>![这是图片](https://blog.meowrain.cn/api/i/2023/04/12/1239qir.webp)
>编辑的过程中，点击上方的「Preview changes」选项卡，查看 Markdown 渲染后的效果


上面的文章详细说明了如何 pull requests
如果有厉害的学弟学妹，欢迎大家来补充这个文档！


