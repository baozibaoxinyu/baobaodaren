//�����������������
//������ı�ģʽ���ж���Ķ�ȡ���������ַ��������������ֿո���ɶ�ȡʧ�ܣ����Ӧ��ʹ�ö�����
//ģʽ���ж�ȡ��д��
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
		//outFile << book;	//�ı�ģʽд��
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
		//inFile >> book1;	//�ı�ģʽд��
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