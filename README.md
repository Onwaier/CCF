# CCF历年真题解析
## 201909-1
水题，题解见[博客](https://onwaier.blog.csdn.net/article/details/102565209)
## 201909-2
水题, 第一次只得了90分，在E的理解上与题目有偏差。认为只有三棵树时，连续三棵树有苹果掉落的组数最大应该为1，其它2种情况应该是重复的。
题解见[博客](https://onwaier.blog.csdn.net/article/details/102605811)
## 201909-3
有点复杂，参考[博客](https://blog.csdn.net/richenyunqi/article/details/101399918)。

需要注意的是：
对于命令行中的RGB值，要先将10进制的RGB值转换成字符串，再按16进制数形式逐个字符地输出。例如一个RGB的一个颜色分量值为128，需要按16进制数的形式分别输出1、2、8这3个字符，而不是直接按16进制数形式输出128这个10进制数。这里题目没有明说，需要根据例子体会。
## 201909-4
题解见[博客](https://onwaier.blog.csdn.net/article/detail
s/102727324)

**注意点**
- #define NUM 1000000000 会溢出 ;
- res[t]不用排序 

**技巧**
- id用哈希函数 type*10^9 + comm   方便映射 ;
- map存储对应id在set中插入的位置 关联式容器插入删除元素不影响其它结点的迭代器 ;
- set.insert()的返回值是pair<set<T>::iterator, bool> 

## 201903-1
题解见[博客](https://onwaier.blog.csdn.net/article/details/102759653)

**注意点**
中位数可能为整数或者小数，需要分情况考虑。

## 201903-2
题解见[博客](https://onwaier.blog.csdn.net/article/details/102811294)

这个题是数据结构中栈的简单应用：将中缀表达式转为后缀表达式。

## 201903-3
题解见[博客](https://onwaier.blog.csdn.net/article/details/102854729)

## 201903-4
题解见[博客](https://onwaier.blog.csdn.net/article/details/102907704)

## 201812-1
题解见[博客](https://onwaier.blog.csdn.net/article/details/102922755)

## 201812-2
题解见[博客](https://onwaier.blog.csdn.net/article/details/102936182)

**注意**:
1. 模拟前可以将当前所花时间mod红绿灯黄一个周期时间之和，可以节省时间，不然会超时。因为t会很大的。
2. 因为t会很大，所以数据类型不能用int。我用的是long long 。

## 201812-3
题解见[博客](https://onwaier.blog.csdn.net/article/details/102976454)

## 201812-4
题解见[博客](https://onwaier.blog.csdn.net/article/details/102986675)

## 201809-1
题解见[博客](https://onwaier.blog.csdn.net/article/details/103008891)

## 201809-2
题解见[博客](https://blog.csdn.net/happyeveryday62/article/details/103035781)

## 201809-3
题解见[博客](https://blog.csdn.net/happyeveryday62/article/details/103075131)

## 201809-4
题解见[博客](https://blog.csdn.net/happyeveryday62/article/details/103106187)

## 201803-1
题解见[博客](https://onwaier.blog.csdn.net/article/details/103134372)

## 201803-2
题解见[博客](https://onwaier.blog.csdn.net/article/details/103141045)
