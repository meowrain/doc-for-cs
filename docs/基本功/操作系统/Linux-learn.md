# Linux

[Linux-wikedpad-Linux 维基百科](https://zh.wikipedia.org/wiki/Linux)

# Linux 发行版

以下是几个常见的 Linux 发行版：

Ubuntu：Ubuntu 是最受欢迎的 Linux 发行版之一，以易用、稳定和社区支持良好而闻名。它基于 Debian，提供了一个友好的桌面环境和大量的应用程序。

Debian：Debian 是一个稳定、安全的 Linux 发行版，以其广泛的软件库和开发社区而著名。它提供了多种桌面环境和服务器版本，可用于各种用途。

CentOS：CentOS 是基于 Red Hat Enterprise Linux（RHEL）的一个免费开源的 Linux 发行版，提供了类似于 RHEL 的企业级功能和支持。它被广泛用于服务器环境和企业应用。

Fedora：Fedora 是一个社区驱动的 Linux 发行版，由 Red Hat 赞助。它提供了最新的软件和技术，适用于桌面和服务器环境。

Arch Linux：Arch Linux 是一个轻量级、灵活的 Linux 发行版，以其简单、自定义的安装和配置方式而著名。它适用于高级用户和 Linux 爱好者。

# Linux 命令快查

- [⭐Linux 命令快速查询手册](https://wangchujiang.com/linux-command/)

# Linux教程
- [⭐韩顺平linux](https://www.bilibili.com/video/BV1Sv411r7vd/?spm_id_from=333.337.search-card.all.click)
- [Linux Tools Quic Tutorial](https://linuxtools-rst.readthedocs.io/zh_CN/latest/base/index.html)


# Fedora使用体验
## 更换软件源为清华源
https://mirrors.tuna.tsinghua.edu.cn/help/fedora/
> 参考上面清华源官方写的文档那个，进行更换

## 启用flatpak
https://www.flatpak.org/setup/Fedora
> 见上面的文档
```shell
 flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
```
## NVIDIA显卡驱动安装
https://docs.fedoraproject.org/en-US/quick-docs/how-to-set-nvidia-as-primary-gpu-on-optimus-based-laptops
>见上，fedora官方文档，按照上面操作一般是没问题的
## 输入法
### ibus-rime
在Fedora中安装`ibus-rime`
```shell
dnf install ibus-rime
```
#### 配置
https://blog.mikelyou.com/2020/07/31/rime-input/
> 可以看上面这个链接里面的，写的很好
