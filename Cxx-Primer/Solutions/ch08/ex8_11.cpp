/*  ex8_11.cpp
**  Exercise 8.11
**
**  @Brief  The program in this section defined its istringstream object inside the outer while loop.
**          What changes would you need to make if record were defined outside that loop?
**          Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

struct PersonInfo {
	std::string name;
	std::vector<std::string> phones;
};
int main() {
	std::string line, word;			// 分别保存来自输入的一行和单词
	std::vector<PersonInfo> people;	// 保存来自输入的所有记录
	std::istringstream record; 	 	// 绑定一条记录,从中提取一个人名和若干电话号码
	// 逐行从输入读取数据,直到cin遇到文件尾或其他错误
	while (std::getline(std::cin, line)) {
		PersonInfo info;			// 创建一个保存此记录数据的对象
		record.clear();				// 恢复流状态为有效
		record.str(line);			// 绑定这一条记录
		record >> info.name;		// 读取名字
		while (record >> word) 		// 读取电话号码
			info.phones.push_back(word); // 保持它们
		people.push_back(info);		// 将此纪录追加到people末尾
	}
	for (const auto &p : people) {
		std::cout << p.name << " ";
		for (const auto &phone : p.phones)
			std::cout << phone << " ";
		std::cout << std::endl;
	}
	return 0;
}