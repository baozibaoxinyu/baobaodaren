//file:Solu_2.cpp
//将字符串数组的所有小写元音字符替换成*
//并将结果输出至屏幕。以lambda表达式的方式定义一个使用
//迭代器的函数来替换字符串的元音字符
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <string>

int main()
{
	std::string words[]{ "Allen","Bob","Celli","David" ,"Elen" };
	for (auto iter{ std::begin(words) }; iter != std::end(words); ++iter) {
		std::cout << *iter << std::endl;
	}
	auto chan = [](std::string a) {
			for (size_t j{}; j < a.size(); ++j) {
				if (a[j] == 'a' || a[j] == 'e' || a[j] == 'i' || a[j] == 'o' || a[j] == 'u')
					a[j] = '*';
			}
			return a;
	};
	std::transform(std::begin(words), std::end(words),
		std::ostream_iterator<std::string>(std::cout, "\n"), chan);
	return 0;
}