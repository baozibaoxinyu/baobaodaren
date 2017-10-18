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
//deque��˫����е���ʽ��֯Ԫ�أ�����������ͷ����β����Ч�������ɾ��Ԫ�أ�����Ҫ��������ʱ������ʹ��
//deque˫�����
template <typename T>
void showDeque(std::deque<T>& dq) {
	for (auto& mem:dq) {
		std::cout << mem<< " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv) 
try{
	//����deque����
	std::deque<int> peoples;//��Ԫ��
	std::deque<int> armies(10);//���ɸ���Ԫ��
	std::deque<std::string> names{ "Bao","Chris","Hellen" };//ʹ�ó�ʼ���б���г�ʼ��
	std::deque<int> for_arm(armies);//ʹ�ø������캯����deque���г�ʼ��
	std::deque<std::string> names_copy{ std::begin(names),std::end(names) };//ʹ��������������ʶһ��Ԫ�ؽ��г�ʼ��
	//����Ԫ�أ����������±��������at������Ԫ�ؽ��з���,at�������Խ�������Խ����
	std::cout << names[1] << " " << names.at(2) << std::endl;
	//��Ӻ��Ƴ�Ԫ�أ�dequeҲ��push_back��pop_back����������ĩβԪ�ؽ������Ӻ�ɾ����������ǰ��ͺ��������������в���
	//��vector��ͬ���ǣ�deque��push_front��pop_front�������Զ�����ͷ���������Ӻ�ɾ��
	//��vector���ƣ�����emplace_back��emplace_front����������deque�Ķ�β�Ͷ�������Ԫ��
	//��vector���ƻ���emplace��insert������������Ԫ�غͲ���Ԫ�أ�������������һЩ����Ϊ����Ԫ���޷�������ʣ���Ҫ��ͷ����
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
	//std::cout << *iter << std::endl;//����ʱ�������Ϊ��iter��������滹��һ�����붯�������붯���ᵼ��֮ǰ���ж���ĵ�����ȫ
	//��ʧЧ����������*iter�ᱨ��
	std::cout << *iter1 << std::endl;
	//�滻deque���������ݣ���Ա����assign�����滻�������е�Ԫ�أ����������ذ汾
	//1���滻�������ݿ������г�ʼ���б�ָ����Ԫ�أ�2���ɵ�����ָ����һ��Ԫ�أ�3��һ���ض�����Ķ������
	names.assign({ "Xilin","Jack","Yelle" });
	//names.assign(std::string{ "Cary" }, std::string{ "Hola" });
	//���벻ͨ��,��Ϊ����ĳ�ʼ���б��ƶ�Ϊinitializer_list<const char*>��assign��Ҫ������Ϊinitializer_list<std::string>��ʵ��
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