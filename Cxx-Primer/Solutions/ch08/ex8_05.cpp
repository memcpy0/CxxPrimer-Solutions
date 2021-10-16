/*  ex8_05.cpp
**  Exercise 8.5
**
**  Created by memcpy on 2021/10/16.
**  @Brief  Rewrite the previous program to store each word in a separate element.
**  @See    ex8_04.cpp
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readFileToVec(const std::string &fileName) {
	std::ifstream input(fileName);
	std::vector<std::string> vec;
	if (input) {
		std::string buf;
		while (input >> buf) 
			vec.push_back(buf);
	}
	return vec;
}
int main() {
	std::vector<std::string> &&vec = readFileToVec("../data/book.txt");
	for (const auto &str : vec)
		std::cout << str << std::endl;		
	return 0;
}