/*  ex8_04.cpp
**  Exercise 8.4
**
**  Created by memcpy on 2021/10/15.
**  @Brief  Write a function to open a file for input and read its contents into a vector of strings, 
**  	storing each line as a separate element in the vector.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> readFileToVec(const std::string &fileName) {
	std::ifstream input(fileName);
	std::vector<std::string> vec;
	if (input) {
		std::string buf;
		while (std::getline(input, buf))
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