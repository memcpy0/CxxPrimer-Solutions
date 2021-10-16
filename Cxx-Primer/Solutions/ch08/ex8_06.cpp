/*  ex8_06.cpp
**  Exercise 8.6
**
**  Created by memcpy on 2021/10/16.
**  @Brief  Rewrite the bookstore program from §7.1.1 (p.256) to read its transactions from a file. 
**          Pass the name of the file as an argument to main (§6.2.5, p.218). 
**  @See    ex7_26.h (use the `Sales_data` class type)
**  @Run    give a parameter: "../data/book.txt"
**  @Output 0-201-78345-X 5 110
**          0-201-78346-X 9 839.2 
*/
#include <fstream>
#include <iostream>
#include "../ch07/ex7_26.h"

int main(int argc, char **argv) {
	std::ifstream input(argv[1]);
	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(std::cout, total) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;	
	} else {
		std::cerr << "No data?!" << std::endl;
	}
	return 0;
}