#ifndef CARTON_H
#define CARTON_H
#include "Box.h"
class Carton : public Box {
public:
	Carton(double lv, double wv, double hv) :Box(lv, wv, hv) {}
	Carton() {}
	Carton(const Carton& carton) {
		length = carton.length;
		height = carton.height;
		width = carton.width;
	}
	~Carton() { std::cout << "Carton destructor called" << std::endl; }
	double volumn() const override {
		return 0.85*length*width*height;
	}
};
#endif