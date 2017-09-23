//file:Solu_2.cpp
//���ַ������������СдԪ���ַ��滻��*
//��������������Ļ����lambda���ʽ�ķ�ʽ����һ��ʹ��
//�������ĺ������滻�ַ�����Ԫ���ַ�
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