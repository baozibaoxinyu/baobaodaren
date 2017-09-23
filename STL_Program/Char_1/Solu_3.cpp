//file:Solu_3.cpp
//利用transform算法，将一个数组的字符串转换为大写，输出结果
#include <iostream>
#include <string>
#include <iterator>
#include <locale>
#include <algorithm>

int main() 
{
	//这是利用c函数库的转换方式
	std::string words[]{ "Allen","Bob","Cylin","David","Elel","Flander" };
	std::transform(std::begin(words),std::end(words),std::ostream_iterator<std::string>(std::cout,"\n"),
		[](std::string a) {
		for (size_t i{}; i < a.size(); ++i) {
			a[i] = toupper(a[i]);
		}
		return a;
	});

}