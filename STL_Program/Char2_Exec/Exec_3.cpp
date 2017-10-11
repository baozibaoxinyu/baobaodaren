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
	//����vector<T>������vector<T>����չ�������������ڲ�������ɾԪ��ʱ����һЩ����Ŀ���
	//ͨ������£����ᵼ�´�����ٶȱ���
	std::vector<int> value;		//��������û��Ԫ�أ����û�з���ռ䣬����ӵ�һ��Ԫ��ʱ������ڴ����
	//�������ڴ�ķ������������ٿ�������20��Ԫ�أ�ʹ����reverse���������еĵ�����ʧЧ����Ҫ������������
	value.reserve(20);
	//���ó�ʼ���б��vector�������г�ʼ����ȷ����Ԫ�����ݺ�Ԫ�ظ�����
	std::vector<int> number{ 1,2,3,4,5,6,7,8 };
	//ָ����vector��������������������20��Ԫ�ص�������Ԫ��ֵΪ0��
	std::vector<int> primes(20);	//��std::vector<int> primes{20}��ͬ��������ֻ��1��Ԫ��
	//ָ��Ԫ�ظ����ͳ�ʼֵ��vector<T>��ʼ��,����20��Ԫ�أ�ȫ��Ϊ99
	std::vector<int> age(20, 99);
	//������Ԫ��������ͬ��vector��������һ���������г�ʼ�����õ�������ָ����ʼֵ�ķ�Χ��
	std::vector<int> age_copy(std::begin(age), std::end(age));
	//Ҳ�������ƶ���������age��Ԫ���ƶ����µ�vector����,�ƶ�����ֵ����
	std::vector<std::string> name_copy(std::make_move_iterator(std::begin(name)), 
		std::make_move_iterator(std::end(name)));
	if (age.empty()) {
		std::cout << "vector age is empty." << std::endl;
	}
	else
		std::cout << name[0] << " " << name.size() << std::endl;

}