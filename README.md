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
题解见[博客](https://onwaier.blog.csdn.net/article/details/102727324)

**注意点 **
- #define NUM 1000000000 会溢出 ;
- res[t]不用排序 

**技巧**
- id用哈希函数 type*10^9 + comm   方便映射 ;
- map存储对应id在set中插入的位置 关联式容器插入删除元素不影响其它结点的迭代器 ;
- set.insert()的返回值是pair<set<T>::iterator, bool> 