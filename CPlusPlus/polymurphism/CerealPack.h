#ifndef CAREALPACK_H
#define CAREALPACK_H
#include "Carton.h"
class CerealPack : public Carton{
public:
	CerealPack(double lv, double wv, double hv) :Carton(lv, wv, hv) {}
	CerealPack() {}
	virtual ~CerealPack() { 
		std::cout << "CerealPack destructor called" << std::endl; 
	}
	double volumn() const override {
		return (length - 0.15)*(width - 0.15)*(height - 0.15);
	}
};
#endif