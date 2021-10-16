/*  ex8_02.cpp
**  Exercise 8.2
**
**  Created by memcpy on 2021/10/15.
**  @Brief  Test your function by calling it, passing cin as an argument
*/
#include <iostream>

std::istream& func(std::istream &is) {
	std::string word;
	while (is >> word)
		std::cout << word << std::endl;
	is.clear(); // reset the stream to make it valid
	return is;
}

int main() {
	std::istream &is = func(std::cin);
	std::cout << is.rdstate() << std::endl;
	return 0;
}