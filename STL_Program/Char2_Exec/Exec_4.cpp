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

//vectorʵ�������п��Է��ص������ĳ�Ա����������const��������non-const������
//vector�ĵ�������������ʵ�������Ҳ����ͨ��ȫ�ֺ������л�ȡ
//�޷���vector�����ж���front_insert_iterator������Ҫpush_front���������ǲ�û�ж���ú���
//����ʹ��back_insert_iterator����Ϊvector����ʹ��push_back��������Ԫ�ز���

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