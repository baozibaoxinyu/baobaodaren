#ifndef ANIMALS_H
#define ANIMALS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <memory>
class Animals {
protected:
	std::string name{ "Fido" };
	size_t weight{};
public:
	Animals(std::string theName, size_t theWeight) :name{ theName }, weight{ theWeight } {}
	Animals() {}
	Animals(const Animals& animal) {
		name = animal.name;
		weight = animal.weight;
	}
	virtual std::string who() const{
		return std::string("My name is " + name + " My weight is " + std::to_string(weight) + " lbs");
	}
	virtual std::string sound() = 0;
};
class Sheep :public Animals {
public:
	Sheep(std::string theName, int theWeight) :Animals(theName, theWeight) {}
	Sheep() {}
	Sheep(const Sheep& sheep) {
		name = sheep.name;
		weight = sheep.weight;
	}
	std::string who()const override {
		return std::string("I am sheep.") + Animals::who();
	}
	std::string sound() override {
		return std::string("meyeeeeeee");
	}
};
class Dog : public Animals {
public:
	Dog(std::string theName, size_t theWeight) :Animals(theName, theWeight) {}
	std::string who() const override {
		return std::string("I am dog.") + Animals::who();
	}
	std::string sound() override {
		return std::string("wowowowo");
	}
};
class Zoo {
private:
	std::vector<std::shared_ptr<Animals>> animals;
public:
	Zoo(std::vector<std::shared_ptr<Animals>> newAnimals) :animals{ newAnimals } {}
	Zoo() {};
	void addAnimal(std::shared_ptr<Animals> animal) {
		animals.push_back(animal);
	}
	void showAnimals(){
		for (size_t i{}; i < animals.size(); ++i) {
			std::cout << animals[i]->who() << std::endl;
			std::cout << "it's sound is " << animals[i]->sound() << std::endl;
		}
	}
};
#endif
