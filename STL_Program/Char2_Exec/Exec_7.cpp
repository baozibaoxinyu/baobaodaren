/*
  Filename:Exec_7.cpp
  Date:18/10/2017
  Author:Chris Bao
  Overview:
  Using deque<T> container
*/
#include <iostream>
#include <deque>
#include <string>
#include <exception>
//deque以双向队列的形式组织元素，可以在容器头部和尾部高效的增添和删减元素，当需要这种需求时，可以使用
//deque双向队列
template <typename T>
void showDeque(std::deque<T>& dq) {
	for (auto& mem:dq) {
		std::cout << mem<< " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv) 
try{
	//生成deque容器
	std::deque<int> peoples;//无元素
	std::deque<int> armies(10);//生成给定元素
	std::deque<std::string> names{ "Bao","Chris","Hellen" };//使用初始化列表进行初始化
	std::deque<int> for_arm(armies);//使用副本构造函数对deque进行初始化
	std::deque<std::string> names_copy{ std::begin(names),std::end(names) };//使用两个迭代器标识一段元素进行初始化
	//访问元素，可以适用下标运算符和at函数对元素进行访问,at函数可以进行索引越界检查
	std::cout << names[1] << " " << names.at(2) << std::endl;
	//添加和移除元素，deque也有push_back和pop_back函数，来对末尾元素进行增加和删除，可以用前向和后向插入迭代器进行插入
	//与vector不同的是，deque有push_front和pop_front函数可以对序列头部进行增加和删除
	//与vector类似，还有emplace_back和emplace_front函数可以在deque的队尾和队首生成元素
	//与vector类似还有emplace和insert函数进行生成元素和插入元素，这个过程相对慢一些，因为访问元素无法随机访问，需要从头遍历
	names.push_back("Vava");
	names.push_front("Alice");
	showDeque(names);
	names.pop_back();
	showDeque(names);
	names.pop_front();
	showDeque(names);
	auto iter = names.emplace(std::begin(names), "Bob");
	auto iter1 = names.insert(std::begin(names) + 2, { "Maven","Node","Leo" });
	showDeque(names);
	//std::cout << *iter << std::endl;//运行时会出错，因为在iter的语句下面还有一个插入动作，插入动作会导致之前所有定义的迭代器全
	//部失效，因此输出的*iter会报错
	std::cout << *iter1 << std::endl;
	//替换deque容器的内容，成员函数assign可以替换所有现有的元素，有三个重载版本
	//1，替换的新内容可以是有初始化列表指定的元素；2，由迭代器指定的一段元素；3，一个特定对象的多个副本
	names.assign({ "Xilin","Jack","Yelle" });
	//names.assign(std::string{ "Cary" }, std::string{ "Hola" });
	//编译不通过,因为里面的初始化列表被推断为initializer_list<const char*>，assign需要的类型为initializer_list<std::string>的实参
	showDeque(names);
	std::string words[]{ "Flex","IBot" };
	names.assign(std::begin(words), std::end(words));
	showDeque(names);
	names.assign(10, "Tizi");
	showDeque(names);
	getchar();
	return 0;
}
catch (std::exception& ex) {
	std::cout << typeid(ex).name() << ":" << ex.what() << std::endl;
}