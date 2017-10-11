/*
  filename:Exec_3.cpp
  date:11/10/2017
  author:Chris Bao
  overview:
  define vector<T> and some case that use its function
*/
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
int main()
{
	std::vector<std::string> name{ "Chris","Baozi","Chris" };
	//创建vector<T>容器，vector<T>在扩展容量和在序列内部进行增删元素时会有一些额外的开销
	//通常情况下，不会导致代码的速度变慢
	std::vector<int> value;		//由于容器没有元素，因此没有分配空间，当添加第一个元素时会进行内存分配
	//设置了内存的分配容量，至少可以容纳20个元素，使用了reverse后所有现有的迭代器失效，需要重新生成他们
	value.reserve(20);
	//利用初始化列表对vector容器进行初始化。确定了元素内容和元素个数。
	std::vector<int> number{ 1,2,3,4,5,6,7,8 };
	//指定了vector容器的容量，该容器有20个元素的容量，元素值为0。
	std::vector<int> primes(20);	//与std::vector<int> primes{20}不同，这个情况只有1个元素
	//指定元素个数和初始值的vector<T>初始化,包含20个元素，全部为99
	std::vector<int> age(20, 99);
	//可以用元素类型相同的vector容器对另一个容器进行初始化。用迭代器来指定初始值的范围。
	std::vector<int> age_copy(std::begin(age), std::end(age));
	//也可以用移动迭代器将age的元素移动到新的vector容器,移动是右值引用
	std::vector<std::string> name_copy(std::make_move_iterator(std::begin(name)), 
		std::make_move_iterator(std::end(name)));
	if (age.empty()) {
		std::cout << "vector age is empty." << std::endl;
	}
	else
		std::cout << name[0] << " " << name.size() << std::endl;

}