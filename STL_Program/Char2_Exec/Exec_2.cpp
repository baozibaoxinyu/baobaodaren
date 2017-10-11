/*
  filename:Exec_2.cpp
  date:10/10/2017
  author:Chris Bao
  overview:
  some practice about iterator in array<T,N> and comparation between array<T,N>
*/
#include <iostream>
#include <algorithm>	//for generate() function
#include <numeric>		//for iota() function
#include <array>
#include <iterator>
#include <exception>
int main()
{
	//在数组中利用函数begin()和end()得到指向第一个元素和最后一个元素的后一个位置的随机访问迭代器
	//随机访问迭代器拥有最多的功能，可以实现全部的迭代器功能
	std::array<int, 10> age;
	auto first = age.begin();
	auto last = age.end();
	int fir = 1;
	//这个循环将指向第一个元素的迭代器的位置进行递增，直到数组最后的元素后一个位置停止
	while (first != last) {
		*(first++) = fir++;
	}
	for (size_t i{}; i < age.size(); ++i) {
		std::cout << age.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "the value of first iterator pointed to is " << *(first-1) << std::endl;
	//利用全局的begin()函数和end()函数获得通用的迭代器
	//利用algorithm头文件的generate()函数进行初始化一段元素
	std::array<int, 10> numbers;
	int i{ 1 };
	std::generate(std::begin(numbers),std::end(numbers),
		[&fir,i]() {
		return fir+=i;
	});
	for (size_t i{}; i < numbers.size(); ++i) {
		std::cout << numbers.at(i) << " ";
	}
	std::cout << std::endl;
	//除了上述的迭代器，还有cbegin()和cend()函数以及rbegin()和rend()函数来获取相应的迭代器
	//c表示const，r表示reverse
	//比较数组容器
	//数组的排序是按照字典顺序进行排序的，从第一个字母开始进行相互比较。
	std::array<double, 5> number1{ 1,2,3,4,5 };
	std::array<double, 5> number2{ 1,1,2,3,4 };
	std::array<double, 5> number3{ 1,4,1,1,1 };
	if (number1 > number2)
		std::cout << "number1 is bigger than number2." << std::endl;
	else
		std::cout << "number2 is bigger than number1." << std::endl;
	if (number2 > number3)
		std::cout << "number2 is bigger than number3." << std::endl;
	else
		std::cout << "number3 is bigger than number2." << std::endl;
	if (number1 > number3)
		std::cout << "number1 is bigger than number3." << std::endl;
	else
		std::cout << "number3 is bigger than number1." << std::endl;
	return 0;
}