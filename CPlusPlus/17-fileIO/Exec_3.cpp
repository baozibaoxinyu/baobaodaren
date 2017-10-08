//file:Exec_3
//计算质数并将质数写入文件中，同时可以在文件中读取质数并显示在屏幕中
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <stdlib.h>
typedef unsigned long long ulong;
static int primeNumberInFile;
const int perline{ 10 };
void writePrimesInFile(std::ofstream& outFile, int primeNumber);
void readPrimesFromFile(std::ifstream& inFile,int primeNumber,std::string filename);

int main()
{
	int primeNumber{};
	std::cout << "Please input prime number:";
	std::cin >> primeNumber;
	primeNumberInFile = primeNumber;
	std::cout << "Writing data..." << std::endl;
	std::string filename{ "E:\\LearnC++\\16-fileIO\\exercise\\Exercise_File\\prime_file.txt" };
	std::ofstream outFile;
	outFile.open(filename);
	if (!outFile.fail()) {
		writePrimesInFile(outFile, primeNumber);
		std::cout << "Success to write file.\n";
	}
	else {
		std::cout << "Failed open file." << std::endl;
	}
	std::ifstream inFile{ filename };
	if (!inFile.fail()) {
		std::cout << "Please input prime number you want to show in screen:";
		std::cin >> primeNumber;
		readPrimesFromFile(inFile, primeNumber,filename);
	}
	else
		std::cout << "Fail to open file." << std::endl;
	//system("pause");
	return 0;
}
void writePrimesInFile(std::ofstream& outFile, int primeNumber) {
	switch (primeNumber) {
	case 1:
		outFile << std::setw(10) << std::left << 2ULL;
		outFile.close();
		break;
	case 2:
		outFile << std::setw(10) << std::left << 2ULL << std::setw(10) << 3ULL;
		outFile.close();
		break;
	case 3:
		outFile << std::setw(10) << std::left << 2ULL << std::setw(10) << 3ULL << std::setw(10) << 5ULL;
		outFile.close();
		break;
	default:
		break;
	}
	if (primeNumber > 3) {
		outFile << std::setw(10) << std::left << 2ULL << std::setw(10) << 3ULL << std::setw(10) << 5ULL;
		ulong lastPrime = 5ULL;
		bool isPrime = true;
		int count = 3;
		while (++count <= primeNumber) {
			isPrime = true;
			lastPrime += 2;
			for (ulong i{ 2ULL }; i <= static_cast<ulong>(sqrt(lastPrime)); ++i) {
				if (lastPrime%i == 0) {
					isPrime = false;
					count = count - 1;
					break;
				}
			}
			if (isPrime) {
				outFile << std::setw(10) << lastPrime << (count % perline == 0 ? "\n" : "");
			}
		}
		outFile.close();
	}
}
void readPrimesFromFile(std::ifstream& inFile, int primeNumber,std::string filename) {
	ulong prime;
	int count{};
	if (primeNumber < primeNumberInFile) {
		while (count < primeNumber) {
			inFile >> prime;
			if (inFile.eof()) break;
			std::cout << std::setw(10) << std::left << prime << ((++count % perline == 0) ? "\n" : "");
		}
	}
	else {
		std::ofstream outFile{ filename };
		writePrimesInFile(outFile, primeNumber);
		inFile.close();
		inFile.open(filename);
		while (count < primeNumber) {
			inFile >> prime;
			if (inFile.eof()) break;
			std::cout << std::setw(10) << std::left << prime << ((++count % perline == 0) ? "\n" : "");
		}
	}
}