/*
  filename:Exec_4.cpp
  date:14/10/2017
  author:Chris Bao
  overview:
  using vector iterator
*/
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

//vector实现了所有可以返回迭代器的成员函数，包括const迭代器和non-const迭代器
//vector的迭代器是随机访问迭代器，也可以通过全局函数进行获取
//无法在vector函数中定义front_insert_iterator，这需要push_front函数，但是并没有定义该函数
//可以使用back_insert_iterator，因为vector可以使用push_back函数进行元素插入

int main()
{
	std::vector <std::string> words;
	std::cout << "Enter words separated by space.Enter Ctrl + Z on a separate line to end." << std::endl;
	std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>{},
		std::back_inserter(words));
	std::sort(words.begin(), words.end());
	std::copy(words.cbegin(), words.cend(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << "\n";
	return 0;
}