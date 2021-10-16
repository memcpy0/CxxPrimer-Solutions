/*  ex8_08.cpp
**  Exercise 8.8
**
**  Created by memcpy on 2021/10/16.
**  @Brief  Revise the program from the previous exercise to append its output to its given file.
**          Run the program on the same output file at least twice to ensure that the data are preserved
**  @See    ex8_07.cpp
**  @Run    give a parameter: "../data/book.txt ../data/out.txt"
**  @Output 0-201-78345-X 5 110
**          0-201-78346-X 9 839.2 
*/
#include <fstream>
#include <iostream>
#include "../ch07/ex7_26.h"

int main(int argc, char **argv) {
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2], std::ofstream::app); // or std::ofstream::out | std::ofstream::app
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