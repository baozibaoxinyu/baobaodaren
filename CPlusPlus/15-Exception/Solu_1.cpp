#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CurveBall.h"
int random(int count) {
	return static_cast<int>(count*static_cast<long>(rand()) / (RAND_MAX + 1));
}
void test(int count) {
	if (random(count) <= 5) {
		throw CurveBall("random number is less than or equal with 5.");
	}
}
void handler(){
	std::cout << "too many exception called!" <<std::endl;
	std::exit(1);
}
int main()
{
	int count = 0;
	std::srand(unsigned(std::time(0)));
	std::terminate_handler pHandler{ std::set_terminate(handler) };
	for (int i{}; i < 1000;++i) {
		try {
			test(20);
		}
		catch (std::exception& ex) {
				++count;
				if (count > 10)
					throw TooManyException("Too many exception");
			std::cout << "Exception caught in main." << ex.what() << std::endl;
		}
	}
	std::cout << "The number of excetion is " << count << std::endl;
	return 0;
}