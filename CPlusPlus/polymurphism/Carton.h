#ifndef CARTON_H
#define CARTON_H
#include "Box.h"
#include <string>
class Carton : public Box{
private:
    std::string name = "Carton";
public:
    Carton(double lv,double wv,double hv,std::string theName):
        Box(lv,wv,hv),name{theName} {}
    Carton(std::string theName):name{theName}{}
    Carton(){}
    double volumn() override {
        return 0.85*length*width*height;
    }
};
#endif
