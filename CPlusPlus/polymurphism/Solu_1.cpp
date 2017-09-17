/*
在Animal头文件里定义了Animal类和其派生类：Sheep类，Dog类
定义了Zoo类，存储Animal类
利用生成随机数进行Animal类对象的定义
*/
#include <iostream>
#include <cstdlib>//包含rand()函数和srand()函数
#include <ctime>  //time(0)的头文件
#include <vector>
#include <memory>
#include "Animal.h"
int random(size_t count) {
	//rand函数返回一个[0,RAND_MAX]之间的随机数
	//因此static_cast<long>(rand()) / (RAND_MAX + 1L)产生的是一个0-1之间的随机数
	return static_cast<size_t>((count*static_cast<long>(rand()) / (RAND_MAX + 1L)));
}

int main()
{
	//srand函数为rand函数提供一个初始的种子，在使用rand函数之前自动调用srand函数
	//如果给srand函数指定了初始值，则会以seed作为初始值进行随机数生成
	//time(0)的类型为time_t，被定义为长整型
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