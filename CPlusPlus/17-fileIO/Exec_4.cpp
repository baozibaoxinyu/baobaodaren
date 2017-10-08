#include <iostream>
#include <fstream>
#include <string>

int main(int argc,char* argv[])
{
	std::string  outFileName{ "E:\\LearnC++\\16-fileIO\\exercise\\Exercise_File\\prime_file1.txt" };
	std::string inFileName{ "E:\\LearnC++\\16-fileIO\\exercise\\Exercise_File\\prime_file.txt" };
	std::ofstream outFile{ outFileName,std::ios::binary | std::ios::trunc };
	std::ifstream inFile{ inFileName,std::ios::binary | std::ios::in};
	char ch{};
	while (inFile.get(ch)) {
		outFile.put(ch);
	}
	if (inFile.eof()) {
		std::cout << inFileName << " copied to " << outFileName << " successfully." << std::endl;
	}
	else
		std::cout << "Error copying file.";
}