#ifndef BOX_H
#define BOX_H
#include <iostream>
class Box{
protected:
    double length = 0;
    double width = 0;
    double height = 0;
public:
    Box(double theLength,double theWidth,double theHeight):
        length{theLength},width{theWidth},height{theHeight}{}
    Box(){}
    Box(const Box& box){
        length = box.length;
        width = box.width;
        height = box.height;
    }
    virtual double volumn(){
        return length*width*height;
    }
    void showVolumn(){
        std::cout << "the volumn is " << volumn() << std::endl;
    }
};
#endif
