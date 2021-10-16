/*  ex8_10.cpp
**  Exercise 8.10
**
**  @Brief  Write a program to store each line from a file in a vector<string>.
**          Now use an istringstream to read each element from the vector a word at a time.
*/
#include <iostream>
#include <fstream>
#include <sstream>
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
std::istream& print(std::istream &is) {
	std::string word;
	while (is >> word)
		std::cout << word << std::endl;
	is.clear(); // reset the stream to make it valid
	return is;
}
int main() {
	std::vector<std::string> &&vec = readFileToVec("../data/book.txt");
	for (const auto &str : vec) {
		std::istringstream is(str);
		print(is);
	}
	return 0;
}