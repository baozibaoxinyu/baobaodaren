/*
��Animalͷ�ļ��ﶨ����Animal����������ࣺSheep�࣬Dog��
������Zoo�࣬�洢Animal��
�����������������Animal�����Ķ���
*/
#include <iostream>
#include <cstdlib>//����rand()������srand()����
#include <ctime>  //time(0)��ͷ�ļ�
#include <vector>
#include <memory>
#include "Animal.h"
int random(size_t count) {
	//rand��������һ��[0,RAND_MAX]֮��������
	//���static_cast<long>(rand()) / (RAND_MAX + 1L)��������һ��0-1֮��������
	return static_cast<size_t>((count*static_cast<long>(rand()) / (RAND_MAX + 1L)));
}

int main()
{
	//srand����Ϊrand�����ṩһ����ʼ�����ӣ���ʹ��rand����֮ǰ�Զ�����srand����
	//�����srand����ָ���˳�ʼֵ�������seed��Ϊ��ʼֵ�������������
	//time(0)������Ϊtime_t��������Ϊ������
	std::srand(unsigned(std::time(0)));
	std::vector<std::string> sheepName{ "Fido", "Rover"   , "Lassie" , "Lambikins",   "Poochy",
		"Spit", "Gnasher" , "Samuel" , "Wellington" , "Patch" };
	std::vector<std::string> dogName{ "Bozo", "Killer", "Tasty", "Woolly", "Chops",
		"Blackie", "Whitey", "Eric" , "Sean"  , "Shep" };
	size_t minSheepWeight = 80;
	size_t maxSheepWeight = 150;
	size_t minDogWeight = 1;
	size_t maxDogWeight = 50;
	std::vector<std::shared_ptr<Animals>> animals;

	size_t animals_number{};
	std::cout << "please input the number of animals in zoo:";
	std::cin >> animals_number;
	for (size_t i{}; i < animals_number; ++i) {
		switch (random(2)) {
		case 0:animals.push_back(std::make_shared<Sheep>(sheepName[random(sheepName.size())],
			minSheepWeight + random(maxSheepWeight - minSheepWeight + 1)));
			break;
		case 1:animals.push_back(std::make_shared<Dog>(dogName[random(dogName.size())],
			minDogWeight + random(maxDogWeight - minDogWeight + 1)));
			break;
		default:
			std::cout << "\nInvalid animal type selection" << std::endl;
			break;
		}
	}
	Zoo zoo;
	for (size_t i{}; i < animals.size(); ++i) {
		zoo.addAnimal(animals[i]);
	}
	zoo.showAnimals();
	return 0;
}