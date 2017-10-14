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
	//vector�������ʹ�С������capacity��size���������صõ�
	std::cout << "the capacity of age_copy is " << age_copy.capacity() << " and the size of age_copy is "
		<< age_copy.size();
	std::cout << std::endl;
	//����ͨ��reserve()����������������������Ԫ�ظ�����û�б䡣���Ե���resize()�����ı�������С,����
	//Ҳ�ᵼ����������������
	age_copy.reserve(30);
	std::cout << "the capacity of age_copy is " << age_copy.capacity() << " and the size of age_copy is "
		<< age_copy.size();
	std::cout << std::endl;
	//resize�ļ����÷���
	age_copy.resize(15);
	for (size_t i{}; i < age_copy.size(); ++i) {
		std::cout << age_copy[i] << " ";
	}
	std::cout << "\nthe capacity of age_copy is " << age_copy.capacity() << " and the size of age_copy is "
		<< age_copy.size();
	//����С��������ԭ��������ʱ��vector���Զ��������������������Ϊcapacity 45 size 30
	age_copy.resize(31);
	std::cout << "\nthe capacity of age_copy is " << age_copy.capacity() << " and the size of age_copy is "
		<< age_copy.size();
	//�ڶ�������Ϊ���Ӵ�Сʱ������Ԫ��ֵ������������������ֵΪ31-33��λ�����ֵΪ99��Ԫ��
	//�ڼ�������ʱ���ڶ���������������
	//age_copy.resize(34, 99);
	std::cout << std::endl;
	for (size_t i{}; i < age_copy.size(); ++i) {
		std::cout << age_copy[i] << " ";
	}
	std::cout << "\nthe capacity of age_copy is " << age_copy.capacity() << " and the size of age_copy is "
		<< age_copy.size();
	//����Ԫ�أ�����ͨ���±����������at����������ӦԪ�صķ��ʣ��Ƽ�ʹ��at���������Զ�����Խ����м��
	//����ʹ��front��back�������������е�һ�������һ��Ԫ�ص�����
	std::cout << "\nthe first and the last elements in vector are : first "
		<< age_copy.front() << " and last " << age_copy.back();
	//��Ϊfront��back�������ص������ã����Գ����ڵȺ����
	age_copy.back() = 12;
	std::cout << "\nlast element is " << age_copy.back();
	//ʹ��data�������Է���һ��ָ�������ָ�룬�������ڲ������洢Ԫ��
	auto pData = age_copy.data();
	std::cout << std::endl << pData[0] << std::endl;

}