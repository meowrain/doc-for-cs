# 正则表达式

![](https://static.meowrain.cn/i/2023/04/04/zhzwe9-3.webp)

- [正则表达式](#正则表达式)
  - [正则表达式介绍](#正则表达式介绍)
  - [学习正则表达式](#学习正则表达式)
  - [练习正则表达式](#练习正则表达式)
- [笔记区](#笔记区)
  - [练习1](#练习1)
  - [练习2](#练习2)
  - [练习3](#练习3)

## 正则表达式介绍

> 正则表达式（Regular Expression，简称 regex 或 regexp）是一种用于匹配字符串中特定模式的工具。它由一系列字符和特殊符号组成，可以用来描述复杂的文本模式。正则表达式在文本处理、数据验证和搜索等领域都有广泛应用。许多编程语言都支持正则表达式，例如 Python、JavaScript 和 Java 等。

## 学习正则表达式

Github 上一个很棒的项目，有多个语种的翻译，大家可以来这里学习，在下面的网站中练习

- [⭐learn-regex
  ](https://github.com/ziishaned/learn-regex/blob/master/translations/README-cn.md)

## 练习正则表达式

非常棒的一个练习正则表达式的网站

- [⭐regex101](https://regex101.com)
- [菜鸟教程提供的在线练习网站](https://c.runoob.com/front-end/854/)


---

# 笔记区
> 正好在学正则表达式，顺便笔记就做这儿吧

## 练习1 
> Check if a string contains the word word in it (case insensitive)
`/\bword\b/i` 是一个正则表达式，它用于匹配独立的单词 "word"。`\b` 是一个单词边界，它用于匹配单词的开头或结尾
`/i` 标记大小写不敏感。

> 例如，\bword\b 可以匹配字符串 "A word in a sentence" 中的 "word"，但不会匹配 "swordfish" 中的 "word"。
## 练习2
> Use substitution to replace every occurrence of the word i with the word I (uppercase, I as in me). E.g.: i'm replacing it. am i not? -> I'm replacing it. am I not?. A regex match is replaced with the text in the Substitution field when using substitution.
翻译：把单独的 i 换成 I。

解题：
`/\bi\b/g`
> /\bi\b/g 是一个正则表达式，它用于全局匹配独立的单词 "i"。\b 是一个单词边界，它用于匹配单词的开头或结尾。g 是全局匹配标志，它表示匹配所有符合条件的结果，而不仅仅是第一个。

## 练习3
> With regex you can count the number of matches. Can you make it return the number of uppercase consonants (B,C,D,F,..,X,Y,Z) in a given string? E.g.: it should return 3 with the text ABcDeFO!. Note: Only ASCII. We consider Y to be a consonant! Example: the regex /./g will return 3 when run against the string abc.
翻译：找到所有的大写辅音字母： BCDFGH...XYZ

解题：
`(?![AEIOU])[A-Z]`

> (?![AEIOU])[A-Z] 是一个正则表达式，它用于匹配大写辅音字母。
[A-Z] 匹配任意一个大写字母。
(?![AEIOU]) 是一个否定前瞻断言，它表示后面的字符不能是 [AEIOU] 中的任意一个。
因此，这个正则表达式可以匹配任意一个大写辅音字母，例如 "B"，"C"，"D" 等，但不会匹配大写元音字母 "A"，"E"，"I"，"O" 或 "U"。

> 否定前瞻断言（Negative Lookahead Assertion）是一种正则表达式语法，用于匹配不满足特定条件的文本。它的语法形式为 (?!pattern)，其中 pattern 是一个正则表达式。
> 否定前瞻断言会在当前位置向前查找，检查是否不满足 pattern。如果不满足，则匹配成功；否则，匹配失败。
> 例如，正则表达式 /\d(?!00)/ 可以匹配任意一个数字，但这个数字后面不能紧跟着两个零。因此，它可以匹配字符串 "100" 中的第一个 "1"，但不会匹配字符串 "1000" 中的第一个 "1"。

然后再更新吧。。。。。