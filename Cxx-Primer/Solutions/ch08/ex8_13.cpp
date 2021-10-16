 
/*  ex8_13.cpp
**  Exercise 8.13
**
**  @Brief  Rewrite the phone number program from this section to read from
**          a named file rather than from cin.
**  @See    ex8_11.cpp
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct PersonInfo {
	std::string name;
	std::vector<std::string> phones;
};
bool valid(const std::string &str) {
	return std::isdigit(str[0]);
}
std::string format(const std::string &str) {
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main() {
	std::ifstream ifs("../data/phonenumbers.txt");
	if (ifs) {
		std::string line, word;			// 分别保存来自输入的一行和单词
		std::vector<PersonInfo> people;	// 保存来自输入的所有记录
		std::istringstream record; 	 	// 绑定一条记录,从中提取一个人名和若干电话号码
		// 逐行从输入读取数据,直到ifs遇到文件尾或其他错误
		while (std::getline(ifs, line)) {
			PersonInfo info;			// 创建一个保存此记录数据的对象
			record.clear();				// 恢复流状态为有效
			record.str(line);			// 绑定这一条记录
			record >> info.name;		// 读取名字
			while (record >> word) 		// 读取电话号码
				info.phones.push_back(word); // 保持它们
			people.push_back(info);		// 将此纪录追加到people末尾
		}
		for (const auto &entry : people) { 	// 对people中每一项
			std::ostringstream formatted, badNums;	// 每个循环步创建的对象
			for (const auto &nums : entry.phones) { // 对每个数
				if (!valid(nums)) 
					badNums << " " << nums; // 将数的字符串形式存入badNums
				else // 将格式化的字符串写入formatted
					formatted << " " << format(nums);
			}
			if (badNums.str().empty()) 		// 没有错误的数
				std::cout << entry.name << " " // 打印名字
						<< formatted.str() << std::endl; // 和格式化的数
			else // 否则，打印名字和错误的数
				std::cerr << "input error: " << entry.name
                 		<< " invalid number(s) " << badNums.str() << std::endl;
		}
	} else
		std::cerr << "No phone numbers?!" << std::endl;
	return 0;
}
   