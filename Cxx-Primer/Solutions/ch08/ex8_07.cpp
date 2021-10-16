/*  ex8_07.cpp
**  Exercise 8.7
**
**  Created by memcpy on 2021/10/16.
**  @Brief  Revise the bookstore program from the previous section to write its output to a file.
**          Pass the name of that file as a second argument to main.
**  @See    ex8_06.cpp
**  @Run    give a parameter: "../data/book.txt" "../data/out.txt"
**  @Output 0-201-78345-X 5 110
**          0-201-78346-X 9 839.2 
*/
#include <fstream>
#include <iostream>
#include "../ch07/ex7_26.h"

int main(int argc, char **argv) {
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);
	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(output, total) << std::endl;
				total = trans;
			}
		}
		print(output, total) << std::endl;	
	} else {
		std::cerr << "No data?!" << std::endl;
	}
	return 0;
}