# Git配置代理
首先配置http和https代理

```
git config --global http.proxy 127.0.0.1:7890
git config --global https.proxy 127.0.0.1:7890
```

然后是ssh代理

到你的User目录下

![1692930477362](image/git-env-config/1692930477362.png)

```
Host github.com
  HostName ssh.github.com
  User git
  Port 443
  ProxyCommand connect -S 127.0.0.1:7890 %h %p
```

然后把这段粘贴进去，这样上传下载仓库肯定就没问题了

> 上面的端口不是v2的是clash的，v2的自己改一下
