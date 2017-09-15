#ifndef BOX_H
#define BOX_H
#include <iostream>
class Box {
protected:
	double length{};
	double width{};
	double height{};
public:
	Box(double lv, double wv, double hv) :length{ lv }, width{ wv }, height{ hv } {}
	Box() {}
	Box(const Box& box) {
		length = box.length;
		width = box.width;
		height = box.height;
	}
	~Box() {
		std::cout << "Box destructor called" << std::endl;
	}
	virtual double volumn() const{
		return length*width*height;
	}
	void showVolumn() const{
		std::cout << "Box volumn is " << volumn() << std::endl;
	}
};
#endif
