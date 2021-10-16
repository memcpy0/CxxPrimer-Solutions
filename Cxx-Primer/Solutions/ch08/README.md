# Chapter 8. The IO Library

## 8.1.2节练习

### Exercise 8.1

> Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.

练习8.1：编写函数，接受一个 `istream&` 参数，返回值类型也是 `istream&` 。此函数要从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。

答：`print` 函数如下：

```cpp
std::istream& print(std::istream &is) {
	std::string word;
	while (is >> word)
		std::cout << word << std::endl;
	is.clear(); // reset the stream to make it valid
	return is;
}
```

### [Exercise 8.2](ex8_02.cpp)

练习8.2：测试函数，调用参数为 `cin` 。

答：`func` 函数返回一个 `istream&` 对象 `cin` ，调用 `rdstate()` 查看 `cin` 的当前条件状态，输出值为 `0` ，说明 `cin` 现在处于有效状态。

### Exercise 8.3
> What causes the following while to terminate?

练习8.3：什么情况下，下面的 `while` 循环会终止？
```cpp
while (cin >> i) /* ... */
```

答：当 `cin` 处于错误状态时，`!cin.fail()` 或者 `cin.good()` 为 `false` ，即流 `cin` 的 `eofbit, failbit, badbit` 中任一个或多个被置位，此时检测流状态的条件会失败， `while` 循环会终止。可能的原因有——流到达了文件结束（`eofbit, failbit` 被置位）、输入与 `i` 类型不符的值（`failbit` 被置位）、系统级错误如不可恢复的读写错误（`badbit`被置位）。

## 8.2.1节练习

### [Exercise 8.4](ex8_04.cpp)
练习8.4：编写函数，以读模式打开一个文件，将其内容读入到一个 `string` 的 `vector` 中，将每一行作为一个独立的元素存入 `vector` 中。

答：假设数据文件为 `../data/book.txt` ，每次从中读取一行内容（即书的ISBN号、售出册数和销售价格）为 `string` ，存入 `vector` 中。


### [Exercise 8.5](ex8_05.cpp)
练习8.5：重写上面的程序，将每个单词作为一个独立的元素进行存储。

答：假设数据文件为 `../data/book.txt` ，每次从中读取一个单词为 `string` 并存入 `vector` 中，单词依次是书的ISBN号、售出册数、销售价格。

### [Exercise 8.6](ex8_06.cpp)
练习8.6：重写7.1.1节的书店程序（第229页），从一个文件中读取交易记录。将文件名作为一个参数传递给 `main`（参见**6.2.5节**，第196页）。

答：7.1.1节的书店程序（第229页如下所示）：

```cpp
Sales_data total;					// 保存当前求和结果的数量
if (read(cin, total)) {				// 读入第一笔交易
    Sales_data trans;				// 保存下一条交易数据的变量
    while (read(cin, trans)) {		// 读入剩余的交易
        if (total.isbn() == trans.isbn()) // 检查isbn
            total.combine(trans);		  // 更新变量total当前的值
        else {
            print(cout, total) << endl;   // 输出结果
            total = trans;				  // 处理下一本书
        }
    }
    print(cout, total) << endl;			  // 输出最后一笔交易
} else {								  // 没有输入任何消息
    cerr << "No data?!" << endl;		  // 通知用户
}
```

不过也不必舍近求远，8.2.1节的**用 `fstream` 代替 `iostream&`** 中为我们准备好了更近一步的梯子：

```cpp
ifstream input(argv[1]);   			// 打开销售记录文件 
ofstream output(argv[2]);  			// 打开输出文件
Sales_data total;		   			// 保存销售总额的数量
if (read(input, total)) {  			// 读取第一条销售记录
	Sales_data trans;	   			// 保存下一条销售记录
	while (read(input, trans)) { 		  // 读取剩余记录
		if (total.isbn() == trans.isbn()) // 检查isbn
			total.combine(trans);		  // 更新销售总额
		else {
			print(output, total) << endl; // 打印结果
			total = trans; 				  // 处理下一本书
		}
    }
	print(output, total) << endl; 		  // 打印最后一本书的销售额
} else									  // 文件中无输入数据
	cerr << "No data?!" << endl;
```

我们只需要稍微改写一下上面的程序即可。注意，程序中要用到 `Sales_data` 类类型，为此可以使用[7.3.1节练习 Exercise 7.26](../ch07/ex7_26.h)中完成的 `Sales_data` 类，在程序中导入相关头文件 `"../ch07/ex7_26.h"` 。

完成程序的编写后，在当前目录中使用如下命令，编译链接、执行程序：

```bash
$ g++ -c "../ch07/ex7_26.cpp"
$ g++ -c "ex8_06.cpp"
$ g++ -o ex8_06.exe ex7_26.o ex8_06.o
$ ./ex8_06.exe "../data/book.txt" # 执行程序
0-201-78345-X 5 110
0-201-78346-X 9 839.2
```

## 8.2.2节练习

### [Exercise 8.7](ex8_07.cpp)
练习8.7：修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给 `main` 函数。

答：几乎是8.2.1节的**用 `fstream` 代替 `iostream&`** 程序的复刻。完成程序的编写后，在当前目录中使用如下命令，编译链接、执行程序：

```bash
$ g++ -c "../ch07/ex7_26.cpp"
$ g++ -c "ex8_07.cpp"
$ g++ -o ex8_07.exe ex7_26.o ex8_07.o
$ ./ex8_07.exe "../data/book.txt" "../data/out.txt" # 执行程序
```

现在打开 `data` 目录下的 `out.txt` 文件，即可看到我们想要的输出。

### [Exercise 8.8](ex8_08.cpp)

练习8.8：修改上一题的程序，将结果追加到给定的文件末尾。对同一个输出文件，运行程序至少两次，检验数据是否得以保留。

答：完成程序的编写后，在当前目录中使用如下命令，编译链接、执行程序：

```bash
$ g++ -c "../ch07/ex7_26.cpp"
$ g++ -c "ex8_08.cpp"
$ g++ -o ex8_08.exe ex7_26.o ex8_08.o
$ ./ex8_08.exe "../data/book.txt" "../data/out.txt" # 执行程序
```

现在打开 `data` 目录下的 `out.txt` 文件，发现 `../data/book.txt` 文件的内容被输出了两次，即前一次输出的数据保留了下来。

```tex
0-201-78345-X 5 110
0-201-78346-X 9 839.2
0-201-78345-X 5 110
0-201-78346-X 9 839.2
```

## 8.3.1节练习

### [Exercise 8.9](ex8_09.cpp)

练习8.9：使用你为8.1.2节第一个练习所编写的函数，打印一个 `istringstream` 对象的内容。

答：使用Exercise 8.1的函数 `print` 打印一个 `istringstream` 对象的内容，每次读取并打印一个单词。

### [Exercise 8.10](ex8_10.cpp)

练习8.10：编写程序，将来自一个文件中的行保存在一个 `vector<string>` 中，然后使用一个 `istringstream` 从 `vector` 读取数据元素，每次读取一个单词。

答：参照Exercise 8.4——假设数据文件为 `../data/book.txt` ，每次从中读取一行内容（即书的ISBN号、售出册数和销售价格）为 `string` ，存入 `vector` 中。接着对 `vector` 中的每个 `string` ，将其与一个 `istringstream` 对象绑定，再参照Exercise 8.9，使用Exercise 8.1的函数 `print` 读取并打印该 `istringstream` 对象的内容。

### [Exercise 8.11](ex8_11.cpp)

练习8.11：本节的程序在外层while循环中定义了 `istringstream` 对象。如果 `record` 对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将 `record` 的定义移到while循环之外，验证你设想的修改方法是否正确。

答：将 `istringstream` 对象 `record` 的定义移动到while循环之外后，要想复用这一 `istringstream` 对象，需要在每个循环步开头调用继承自 `istream` 的 `clear` 函数，将流的所有条件状态位复位，即将流的状态设为有效。然后调用 `istringstream` 对象的 `str(s)` 函数，设置 `istringstream` 底层字符串对象的新内容为字符串 `line` ，就能继续使用 `>>` 运算符从 `record` 中提取新记录的人名和若干电话号码。

### :star:Exercise 8.12
> Why didn’t we use in-class initializers in PersonInfo?

练习8.12：我们为什么没有在 `PersonInfo` 中使用类初始化？

答：因为我们在这里只需要一个聚集类 `Aggregate class` ，所以不应该有类初始化器，而且也没什么用。关于 `Aggregates`和 `POD` 的讨论见 [Draft C++14 standard](https://github.com/cplusplus/draft/blob/master/papers/n4140.pdf) 和 https://stackoverflow.com/a/27511360 、https://stackoverflow.com/a/27511360。

> An aggregate is an array or a class (Clause 9) with no user-provided constructors (12.1),  no *brace-or-equal-initializers* for non-static data members (9.2), no private or protected  non-static data members (Clause 11), no base classes (Clause 10), and no virtual functions (10.3).

## 8.3.2节练习

### [Exercise 8.13](ex8_13.cpp)
练习8.13：重写本节的电话号码程序，从一个命名文件而非 `cin` 读取数据。

答：参考Exercise 8.11和本节的电话号码程序（如下所示），从命名文件 `../data/phonenumbers.txt` 中读取数据：

```cpp
for (const auto &entry : people) { // 对people中每一项
	ostringstream formatted, badNums; // 每个循环步创建的对象
	for (const auto &nums : entry.phones) { // 对每个数
		if (!valid(nums))
			badNums << " " << nums; 	// 将数的字符串形式存入badNums
		else 							// 将格式化的字符串写入formatted
			formatted << " " << format(nums);
	}
	if (badNums.str().empty())	 		// 没有错误的数
		os << entry.name << " "			// 打印名字
		   << formatted.str() << endl;  // 和格式化的数
	else // 否则，打印名字和错误的数
		cerr << "input error: " << entry.name
			 << " invalid number(s) " << badNums.str() << endl;
}
```

一个问题是，如何实现假定已有的两个函数 `valid` 和 `format` ，以完成电话号码验证和改变格式的功能。简单起见，本人实现的程序中， `valid` 函数只检查电话号码第一个字符是否为数字， `format` 函数仅在电话号码的第3位和第4位、第6位和第7位之间添加 `'-'` 字符。

### Exercise 8.14

> Why did we declare entry and nums as const auto &?

练习8.14：我们为什么将 `entry` 和 `nums` 定义为 `const auto&` ？

答：因为它们都是类类型 `class type` ，不是内置类型 `built-in type`（基本类型），使用引用 `reference` 更有效率；且输出不会改变它们的值，所以添加 `const` 限定符。
