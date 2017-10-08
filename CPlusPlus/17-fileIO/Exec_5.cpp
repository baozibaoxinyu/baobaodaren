//对象的流输入和流输出
//如果用文本模式进行对象的读取，参数有字符串的情况，会出现空格，造成读取失败，因此应该使用二进制
//模式进行读取和写入
#include <iostream>
#include <fstream>
//#include <vector>
#include <string>
#include "Book.h"
int main()
{
	Book book{ "Program C++",24.6 };
	Book book1;
	//std::vector<Book> book2;
	std::string filename{ "E:\\LearnC++\\16-fileIO\\exercise\\Exercise_File\\Book.txt" };
	std::ofstream outFile;
	outFile.open(filename, std::ios::binary);
	if (!outFile.fail()) {
		//outFile << book;	//文本模式写入
		write(outFile, book);
		std::cout << "Success to write file." << std::endl;
		outFile.close();
	}
	else {
		std::cout << "Failed to write file." << std::endl;
	}
	std::ifstream inFile;
	inFile.open(filename, std::ios::binary);
	if (!inFile.fail()) {
		//inFile >> book1;	//文本模式写入
		while (true) {
			read(inFile, book1);
			if (inFile.eof()) break;
		}
		if (inFile.eof()) {
			std::cout << "get to file terminate." << std::endl;
		}
		std::ios::iostate willthrow{ inFile.exceptions() };
		inFile.close();
		std::cout << book1;
		std::cout << "Success to read file." << std::endl;
	}
	else
		std::cout << "Failed to read file." << std::endl;
	return 0;
}