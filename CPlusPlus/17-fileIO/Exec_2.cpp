#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using ulong = unsigned long long;

int main()
{
	std::string filename{ "E:\\LearnC++\\16-fileIO\\exercise\\Exercise_File\\primes.txt" };
	std::ifstream inFile{ filename };
	if (inFile.fail()) {
		std::cout << "Failed to open file." << std::endl;
		return 1;
	}
	ulong aprime{};
	size_t count{};
	size_t perline{ 6 };
	while (1) {
		inFile >> aprime;
		if (inFile.eof()) break;
		std::cout << ((count++ % perline == 0) ? "\n" : "") << std::setw(10) << aprime;
	}
	std::cout << "\n" << count << " primes read from " << filename << std::endl;
	inFile.close();
}