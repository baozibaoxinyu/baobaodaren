/*
��������࣬��Ϊ����������ͳһ��׼��
*/
#ifndef VESSEL_H
#define VESSEL_H
#include <iostream>
class Vessel {
public:
	virtual double volumn() const = 0;
	virtual ~Vessel() {
		std::cout << "Vessel destructor called;" << std::endl;
	}
};
#endif