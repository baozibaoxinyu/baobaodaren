/*
  Filename:Exec_5.cpp
  Date:14/10/2017
  Author:Chris Bao
  Overview:
  Add and delete elements in vector
*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
class A {
private:
	int height{};
	int weight{};
	int width{};
	int depth{};
public:
	A() {}
	A(int hv, int wv, int wiv = 1, int dep = 1) :height{ hv }
		, weight{ wv }, width{ wiv }, depth{ dep } {}
	A(const A& a) {
		height = a.height;
		weight = a.weight;
		width = a.width;
		depth = a.depth;
	}
	void showA() {
		std::cout << "height is " << height << ",weight is " << weight
			<< ",width is " << width << ",depth is " << depth << std::endl;
	}
};

int main()
{
	//可以使用push_back()函数在vector的末尾增加元素。
	std::vector<A> theA(2);
	std::vector<double> height(20);
	height.push_back(21.4);
	std::cout << height.back() << " " << height.size() << " " << height.capacity() << std::endl;
	//emplace_back的作用也是在容器最后增加元素
	//emplace_back的参数是添加到容器中的对象的构造函数所需要的参数。
	//emplace_back用他的参数作为构造函数的参数，直接在容器内生成对象。
	//可以在emplace_back函数内使用尽可能多的参数，只要这些参数是要添加对象的构造函数的参数即可。
	height.emplace_back(14.2);
	A b{ 1,2,3,4 };
	theA.emplace_back(1,2,3,4);
	theA.begin()->showA();
	std::cout  << " " << theA.size() << " " << theA.capacity() << std::endl;
	//使用emplace函数可以在vector容器中插入新的元素,与emplace_back函数一样，均是在容器内部直接生成对象
	//emplace函数的第一个参数是迭代器，确定了元素生成的位置，第一个参数之后的所有参数，均为插入元素的
	//构造函数的参数。返回值为一个指向插入元素的迭代器。
	//height.emplace(++std::begin(height), 12);
	std::cout << height[height.emplace(++std::begin(height), 9)-std::begin(height)] << std::endl;
	std::cout << *height.emplace(++std::begin(height), 12) << std::endl;
	//使用insert函数可以在vector中插入一个或多个元素
	//第一个参数总是一个指向插入点的const或non-const的迭代器，元素会被插入指向元素的前面，如果是反向迭代
	//器，元素会被插入到迭代器所指向元素的后面,返回值为指向插入元素位置的迭代器
	std::vector<std::string> words{ "One","Two","Three" };
	//在指定位置插入元素
	auto iter = words.insert(++std::begin(words), "two");	//指向元素two
	for (auto& word : words) {
		std::cout << word << " ";
	}
	std::cout << *iter << std::endl;
	//插入一个由第二个和第三个参数指定的元素序列，返回的迭代器指向move的第一个元素Five
	std::string move[]{ "Five","Six","Seven" };
	auto iter1 = words.insert(std::end(words), std::begin(move), std::end(move));
	for (auto& word : words) {
		std::cout << word << " ";
	}
	std::cout << *(iter1) << std::endl;
	//在插入点插入多个元素，第二个参数是第三个参数插入的次数
	auto iter2 = words.insert(std::end(words), 2, "s");	//在结尾插入2个s
	for (auto& word : words) {
		std::cout << word << " ";
	}
	std::cout << *iter2 << std::endl;	//指向第一个s
	//在插入点，插入初始化列表指定的元素
	auto iter3 = words.insert(std::end(words), { std::string {"Ten"},std::string {"Eleven"} });
	for (auto& word : words) {
		std::cout << word << " ";
	}
	std::cout << *(iter3) << std::endl;	//指向Ten
	//可以使用vector的clear函数删除所有元素
	words.clear();
	std::cout << words.size() << " " << words.capacity() << std::endl;	//结果为size 0 capacity 15
	//可以使用vector的pop_back()函数删除尾部的元素
	std::vector<double> value(100, 99);
	value.pop_back();
	std::cout << value.size() << " " << value.capacity() << std::endl;	//结果为size 99 capacity 100
	//可以使用shrink_to_fit()函数可以去掉容器中多余的容量
	//这个操作实现了，所有的迭代器失效，需要重新生成
	value.shrink_to_fit();
	//使用erase函数可以删除一个或多个元素，返回一个迭代器
	//value.erase(std::end(value)); //会出错
	auto iter4 = value.erase(std::end(value)-1);	//iter4指向删除元素后的容器的最后一个元素的后一个位置
	std::cout << iter4 - std::end(value) << std::endl;	//结果为0
	value.erase(std::begin(value), std::begin(value) + 97);//删除前97个元素
	std::copy(std::begin(value), std::end(value), std::ostream_iterator<double>(std::cout, " "));
	std::cout << std::endl;
	//使用algorithm头文件的模板函数remove函数可以删除匹配特定值的一段元素
	//remove函数并不能真正的删除容器的元素，只是让数值进行覆盖，如果输出容器的值，会发现第三个参数
	//对应的值被后面的数组覆盖.如果是字符串则会出现覆盖后原位置被空字符串覆盖
	std::remove(std::begin(value), std::end(value), 99);
	std::copy(std::begin(value), std::end(value), std::ostream_iterator<double>(std::cout, " "));
	std::vector<int> numbers{ 1,2,3,3,3,3,3,1,2,4,5,6,3 };
	auto iter5 = std::remove(std::begin(numbers), std::end(numbers), 3);
	std::copy(std::begin(numbers), iter5, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::vector<std::string> book{ "one","none","none","none","two","none","three","four" };
	auto iter6 = std::remove(std::begin(book), std::end(book), "none");
	//通过erase-remove操作，可以将remove操作之后容器剩余的空字符和多余字符删除。
	book.erase(iter6, std::end(book));
	std::copy(std::begin(book), std::end(book), std::ostream_iterator <std::string>(std::cout, ","));
}