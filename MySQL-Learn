# MySQL数据库

### 关系型数据库（RDBMS)

**概念**：建立在关系模型基础上，有多张相互连接的二维表组成的数据库。

**特点**：

1.使用表存储数据，格式统一，便于维护

2.使用SQL语言操作，标准统一，使用方便



### SQL语言

##### SQL通用语法

1.SQL语句可以单行或多行书写，分号结尾

2.SQL语句可以使用空格缩进来增强语句可读性

3.SQL语句不区分大小写，关键字建议使用大写

4.注释：

​           单行注释：--或#

​           多行注释：/*    */



##### 分类

1.DDL 数据定义语言，用来定义数据库对象（数据库，表，字段）

2.DML数据操作语言，用来对数据库表的数据进行增删减

3.DQL数据查询语言，用来查询数据库表的记录

4.DCL数据控制语言，用来创建数据库用户，控制数据库的访问权限



##### DDL

###### **数据库操作**

查询

查询所有数据   `SHOW DATABASES;`

查询当前数据   `SELECT DATABASE();`

创建  `CREATE DATABASE[IF NOT EXISTS]数据库名[DEFAULT CHARSET字符集] [COLLATE 排序规则];`

删除  `DROP DATABASE[IF EXISTS]数据库名;`

使用  `USE 数据库名;`



###### **表操作**

查询

查询当前数据库所有表 `SHOW TABLES;`

查询表结构 `DESC 表名;`

查询指定表的建表语句 `SHOW CERATE TABLE 表名;`

创建

```sql
CREATE TABLE 表名(
字段1 字段1类型[COMMENT 字段1注释],
字段2 字段2类型[COMMENT 字段2注释]
)[COMMENT 表注释];
```

数据类型

数值类型，字符串类型，日期类型；

修改

添加字段 `ALTER TABLE 表名ADD 字段名 类型（长度）[comment 注释][约束];`

修改数据类型 `ALTER TABLE 表名 MODIFY 字段名 新数据类型(长度);`

修改字段名和类型 `ALTER TABLE 表名 CHANGE 旧字段名 新字段名 类型(长度) [COMMENT 注释][约束]`;

删除字段 `ALTER TABLE 表名 DROP 字段名;`

修改表名 `ALTER TABLE 表名 RENAME TO 新表名;`

删除

删除表 `DROP TABLE[IF EXISTS] 表名;`

删除指定表，并重新创建该表 (清空数据)`TRUNCATE TABLE 表名;`



##### MySQL图形化工具

Navicat，Datagrip

Navicat的安装和破解：(https://www.bilibili.com/video/BV1V84y137VG/?p=6&spm_id_from=333.880.my_history.page.click)



##### DML

###### 添加数据  (NSERT)

1.给指定字段添加数据 `INSET INTO 表名（字段名1，字段名2）VALUES(值1，值2);`

2.给全部字段添加数据 `INSET INTO 表名 VALUES(值1，值2);`

3.批量添加数据 

`INSET INTO 表名（字段名1，字段名2）VALUES(值1，值2),(值1，值2);`

`INSET INTO 表名 VALUES(值1，值2),(值1，值2);`

###### 修改数据  (UPDATE)

`UPDATE表名 SET 字段名1 = 值1,字段名2 = 值2， [WHERE 条件];`

注：如果没有条件，会修改整张表的所有数据。

###### 删除数据  (DELETE)

`DELETE FROM 表名 [WHERE 条件]`

注：1.如果没有条件，会删除整张表的所有数据。

​        2.不能删除某一个字段的值。



##### DQL

###### 语法

```SQL
SELECT 
   字段列表
FROM 
   表名列表
WHERE 
   条件列表
GROUP BY 
   分组字段列表
HAVING 
   分组后条件列表
ORDER BY 
   排序字段列表
LIMIT 
   分页参数
```



###### 基本查询

1.查询多个字段

`SELECT 字段1，字段2 FROM 表名;`

`SELECT *FROM 表名;`  查询所有字段返回（不建议写*，效率低）

2.设置别名

`SELECT 字段1[AS 别名1]，字段2[AS 别名2] FROM 表名;`

3.去除重复记录

`SELECT DISTINCT 字段列表 FROM 表名;`



###### 条件查询(WHERE)

1.语法

`SELECT 字段列表 FROM 表名 WHERE 条件列表;`

2.条件

比较运算符，逻辑运算符(与Java，c相似)

与Java，c不同的运算符有：

BETWEEN ... AND ...   在某个范围之内（有最大最小值）

IN（...）在in之后的列表中的值，多选一

LIKE 占位符   模糊匹配（_匹配单个字符，%匹配任意个字符）

IS NULL    是NULL



###### 聚合函数(count,max,min,avg,sum)

1.介绍： 将一列数据作为一个整体，进行纵向计算。

2.常见的聚合函数

```sql
count  统计数量
max    最大值
min    最小值
avg    平均值
sum    求和
```

3.语法

`SELECT 聚合函数（字段列表） FROM 表名;`



###### 分组查询(GROUP BY)

1.语法

`SELECT 字段列表 FROM 表名 [WHERE 条件] GROUP BY 分组字段名 [HAVING 分组后过滤条件];`

2.where和having的区别

执行时机不同：where是分组之前进行过滤，不满足where条件，不参与分组；而having是分组之后对结果进行过滤。

判断条件不同：where不能对聚合函数进行判断，having可以。

注：where>聚合函数>having。

​        分组之后，查询的字段一般为聚合函数和分组字段，查询其他字段无意义。



###### 排序查询(ORDER BY)

1.语法

`SELECT 字段列表 FROM 表名 ORDER BY 字段1  排序方式1，字段2，排序方式2;`

2.排序方式： ASC（ 升序，可省略） DESC (降序，不可省略）。

注：多字段排序，第一个字段相同时，才会根据第二个排序。



###### 分页查询(LIMIY)

1.语法

`SELECT  字段列表 FROM 表名 LIMIT 起始索引，查询记录数;`

注：起始索引从0开始，起始索引=（查询页码-1）*每页显示记录数。

​        limit是MySQL特有，别的数据库是不同的实现。

​        如果查询是第一页数据，起始索引可省，直接简写为 limit 10。
