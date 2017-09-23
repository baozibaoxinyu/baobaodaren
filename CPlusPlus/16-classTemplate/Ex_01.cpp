#include <iostream>
#include <iomanip>
#include "Array.h"
#include "Box.h"

int main()
{
	const size_t nValues{ 50 };
	Array<double> values{ nValues };
	try {
		for (size_t i{}; i < nValues; ++i) {
			values[i] = i + 1;
		}
		size_t perline{ 10 };
		for (size_t i{ nValues - 1 }; i >= 0; --i) {
			std::cout << std::left <<std::setw(5) << values[i];
			if ((i) % perline == 0) std::cout << std::endl;
		}	
	}
	catch (const std::out_of_range& ex) {
		std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;	
	}
	try {
		const size_t nBoxes{ 10 };
		Array<Box> boxes{ nBoxes };
		for (size_t i{}; i < nBoxes; ++i) {
			boxes[i] = Box(i + 1, i + 2, i + 3);
		}
		for (size_t i{}; i <= nBoxes; ++i) {
			std::cout << std::setw(5) << boxes[i].volumn();
		}
	}
	catch (const std::out_of_range& ex) {
		std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;
	}
	return 0;
}