//file:Solu_3.cpp
//����transform�㷨����һ��������ַ���ת��Ϊ��д��������
#include <iostream>
#include <string>
#include <iterator>
#include <locale>
#include <algorithm>

int main() 
{
	//��������c�������ת����ʽ
	std::string words[]{ "Allen","Bob","Cylin","David","Elel","Flander" };
	std::transform(std::begin(words),std::end(words),std::ostream_iterator<std::string>(std::cout,"\n"),
		[](std::string a) {
		for (size_t i{}; i < a.size(); ++i) {
			a[i] = toupper(a[i]);
		}
		return a;
	});

}