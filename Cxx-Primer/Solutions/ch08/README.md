# Chapter 8. The IO Library

## 8.1.2节练习

### Exercise 8.1

> Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.

练习8.1：编写函数，接受一个 `istream&` 参数，返回值类型也是 `istream&` 。此函数要从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。

### [Exercise 8.2](ex8_02.cpp)
练习8.2：测试函数，调用参数为 `cin` 。

### Exercise 8.3
> What causes the following while to terminate?
练习8.3：什么情况下，下面的 `while` 循环会终止？
```cpp
while (cin >> i) /* ... */
```

## 8.2.1节练习

### [Exercise 8.4](ex8_04.cpp)
练习8.4：编写函数，以读模式打开一个文件，将其内容读入到一个 `string` 的 `vector` 中，将每一行作为一个独立的元素存入 `vector` 中。


### [Exercise 8.5](ex8_05.cpp)
练习8.5：重写上面的程序，将每个单词作为一个独立的元素进行存储。

### [Exercise 8.6](ex8_06.cpp)
练习8.6：重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给 `main`（参见**6.2.5节**）。

## 8.2.2节练习

### [Exercise 8.7](ex8_07.cpp)
练习8.7：修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给 `main` 函数。

### [Exercise 8.8](ex8_08.cpp)
练习8.8：修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。


## 8.3.1节练习

### [Exercise 8.9](ex8_09.cpp)

练习8.9：使用你为8.1.2节第一个练习所编写的函数，打印一个 `istringstream` 对象的内容。

### [Exercise 8.10](ex8_10.cpp)

练习8.10：编写程序，将来自一个文件中的行保存在一个 `vector<string>` 中，然后使用一个 `istringstream` 从 `vector` 读取数据元素，每次读取一个单词。

### [Exercise 8.11](ex8_11.cpp)

练习8.11：本节的程序在外层while循环中定义了 `istringstream` 对象。如果 `record` 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将 `record` 的定义移到while循环之外，验证你设想的修改方法是否正确。

### [Exercise 8.12]
> Why didn’t we use in-class initializers in PersonInfo?
练习8.12：我们为什么没有在 `PersonInfo` 中使用类初始化？

## 8.3.2节练习

### Exercise 8.13
练习8.13：重写本节的电话号码程序，从一个命名文件而非 `cin` 读取数据。

### Exercise 8.14
练习8.14：我们为什么将 `entry` 和 `nums` 定义为 `const auto&` ？