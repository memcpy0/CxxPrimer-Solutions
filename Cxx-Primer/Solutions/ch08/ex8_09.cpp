/*  ex8_09.cpp
**  Exercise 8.9
**
**  Created by memcpy on 2021/10/16.
**  @Brief  Use the function you wrote for the first exercise in § 8.1.2 (p.314) to print the contents of an istringstream object.
**  @See    Exercise 8.1
*/
#include <iostream>
#include <sstream>

std::istream& print(std::istream &is) {
	std::string word;
	while (is >> word)
		std::cout << word << std::endl;
	is.clear(); // reset the stream to make it valid
	return is;
}

int main() {
	std::istringstream is("Hello istringstream, there is Cxx-Primer");
	print(is);
	return 0;
}