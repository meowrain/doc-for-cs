# 安装python
去python官网下载最新版就可以了！

# 安装pipx
> https://pipx.pypa.io/stable/

参考上面这个官方文档安装就可以了

```bash
$ sudo pacman -S python-pipx
```

# 安装poetry

> 检查pipx是否安装，如果安装成功

```bash
$ pipx install poetry
```

# 进入到当前项目，安装项目依赖，创建虚拟环境

```bash
$ poetry install --no-root
```

> 因为已经配置好了镜像，所以下载会很快

# 进入当前虚拟环境的shell

```bash
$ poetry self add poetry-plugin-shell
$ poetry shell
```

# 启动当前项目

```bash
$ mkdocs serve
```

