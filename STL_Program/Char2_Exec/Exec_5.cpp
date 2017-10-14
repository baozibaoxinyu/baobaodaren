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
	//����ʹ��push_back()������vector��ĩβ����Ԫ�ء�
	std::vector<A> theA(2);
	std::vector<double> height(20);
	height.push_back(21.4);
	std::cout << height.back() << " " << height.size() << " " << height.capacity() << std::endl;
	//emplace_back������Ҳ���������������Ԫ��
	//emplace_back�Ĳ�������ӵ������еĶ���Ĺ��캯������Ҫ�Ĳ�����
	//emplace_back�����Ĳ�����Ϊ���캯���Ĳ�����ֱ�������������ɶ���
	//������emplace_back������ʹ�þ����ܶ�Ĳ�����ֻҪ��Щ������Ҫ��Ӷ���Ĺ��캯���Ĳ������ɡ�
	height.emplace_back(14.2);
	A b{ 1,2,3,4 };
	theA.emplace_back(1,2,3,4);
	theA.begin()->showA();
	std::cout  << " " << theA.size() << " " << theA.capacity() << std::endl;
	//ʹ��emplace����������vector�����в����µ�Ԫ��,��emplace_back����һ���������������ڲ�ֱ�����ɶ���
	//emplace�����ĵ�һ�������ǵ�������ȷ����Ԫ�����ɵ�λ�ã���һ������֮������в�������Ϊ����Ԫ�ص�
	//���캯���Ĳ���������ֵΪһ��ָ�����Ԫ�صĵ�������
	//height.emplace(++std::begin(height), 12);
	std::cout << height[height.emplace(++std::begin(height), 9)-std::begin(height)] << std::endl;
	std::cout << *height.emplace(++std::begin(height), 12) << std::endl;
	//ʹ��insert����������vector�в���һ������Ԫ��
	//��һ����������һ��ָ�������const��non-const�ĵ�������Ԫ�ػᱻ����ָ��Ԫ�ص�ǰ�棬����Ƿ������
	//����Ԫ�ػᱻ���뵽��������ָ��Ԫ�صĺ���,����ֵΪָ�����Ԫ��λ�õĵ�����
	std::vector<std::string> words{ "One","Two","Three" };
	//��ָ��λ�ò���Ԫ��
	auto iter = words.insert(++std::begin(words), "two");	//ָ��Ԫ��two
	for (auto& word : words) {
		std::cout << word << " ";
	}
	std::cout << *iter << std::endl;
	//����һ���ɵڶ����͵���������ָ����Ԫ�����У����صĵ�����ָ��move�ĵ�һ��Ԫ��Five
	std::string move[]{ "Five","Six","Seven" };
	auto iter1 = words.insert(std::end(words), std::begin(move), std::end(move));
	for (auto& word : words) {
		std::cout << word << " ";
	}
	std::cout << *(iter1) << std::endl;
	//�ڲ���������Ԫ�أ��ڶ��������ǵ�������������Ĵ���
	auto iter2 = words.insert(std::end(words), 2, "s");	//�ڽ�β����2��s
	for (auto& word : words) {
		std::cout << word << " ";
	}
	std::cout << *iter2 << std::endl;	//ָ���һ��s
	//�ڲ���㣬�����ʼ���б�ָ����Ԫ��
	auto iter3 = words.insert(std::end(words), { std::string {"Ten"},std::string {"Eleven"} });
	for (auto& word : words) {
		std::cout << word << " ";
	}
	std::cout << *(iter3) << std::endl;	//ָ��Ten
	//����ʹ��vector��clear����ɾ������Ԫ��
	words.clear();
	std::cout << words.size() << " " << words.capacity() << std::endl;	//���Ϊsize 0 capacity 15
	//����ʹ��vector��pop_back()����ɾ��β����Ԫ��
	std::vector<double> value(100, 99);
	value.pop_back();
	std::cout << value.size() << " " << value.capacity() << std::endl;	//���Ϊsize 99 capacity 100
	//����ʹ��shrink_to_fit()��������ȥ�������ж��������
	//�������ʵ���ˣ����еĵ�����ʧЧ����Ҫ��������
	value.shrink_to_fit();
	//ʹ��erase��������ɾ��һ������Ԫ�أ�����һ��������
	//value.erase(std::end(value)); //�����
	auto iter4 = value.erase(std::end(value)-1);	//iter4ָ��ɾ��Ԫ�غ�����������һ��Ԫ�صĺ�һ��λ��
	std::cout << iter4 - std::end(value) << std::endl;	//���Ϊ0
	value.erase(std::begin(value), std::begin(value) + 97);//ɾ��ǰ97��Ԫ��
	std::copy(std::begin(value), std::end(value), std::ostream_iterator<double>(std::cout, " "));
	std::cout << std::endl;
	//ʹ��algorithmͷ�ļ���ģ�庯��remove��������ɾ��ƥ���ض�ֵ��һ��Ԫ��
	//remove����������������ɾ��������Ԫ�أ�ֻ������ֵ���и��ǣ�������������ֵ���ᷢ�ֵ���������
	//��Ӧ��ֵ����������鸲��.������ַ��������ָ��Ǻ�ԭλ�ñ����ַ�������
	std::remove(std::begin(value), std::end(value), 99);
	std::copy(std::begin(value), std::end(value), std::ostream_iterator<double>(std::cout, " "));
	std::vector<int> numbers{ 1,2,3,3,3,3,3,1,2,4,5,6,3 };
	auto iter5 = std::remove(std::begin(numbers), std::end(numbers), 3);
	std::copy(std::begin(numbers), iter5, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::vector<std::string> book{ "one","none","none","none","two","none","three","four" };
	auto iter6 = std::remove(std::begin(book), std::end(book), "none");
	//ͨ��erase-remove���������Խ�remove����֮������ʣ��Ŀ��ַ��Ͷ����ַ�ɾ����
	book.erase(iter6, std::end(book));
	std::copy(std::begin(book), std::end(book), std::ostream_iterator <std::string>(std::cout, ","));
}