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
	//�����������ú���begin()��end()�õ�ָ���һ��Ԫ�غ����һ��Ԫ�صĺ�һ��λ�õ�������ʵ�����
	//������ʵ�����ӵ�����Ĺ��ܣ�����ʵ��ȫ���ĵ���������
	std::array<int, 10> age;
	auto first = age.begin();
	auto last = age.end();
	int fir = 1;
	//���ѭ����ָ���һ��Ԫ�صĵ�������λ�ý��е�����ֱ����������Ԫ�غ�һ��λ��ֹͣ
	while (first != last) {
		*(first++) = fir++;
	}
	for (size_t i{}; i < age.size(); ++i) {
		std::cout << age.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "the value of first iterator pointed to is " << *(first-1) << std::endl;
	//����ȫ�ֵ�begin()������end()�������ͨ�õĵ�����
	//����algorithmͷ�ļ���generate()�������г�ʼ��һ��Ԫ��
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
	//���������ĵ�����������cbegin()��cend()�����Լ�rbegin()��rend()��������ȡ��Ӧ�ĵ�����
	//c��ʾconst��r��ʾreverse
	//�Ƚ���������
	//����������ǰ����ֵ�˳���������ģ��ӵ�һ����ĸ��ʼ�����໥�Ƚϡ�
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