#include <iostream>
#include <string>
#include "Box.h"
#include "Carton.h"

int main()
{
    Carton carton(3.2,1.3,2.3,"hardboard");
    //box1.showVolumn();
    std::cout << "box volumn " << carton.Box::volumn() << std::endl;
    carton.showVolumn();
    std::cout << "carton volumn " << carton.volumn() << std::endl;
    Box* pBox = &carton;
    //Carton* pCarton = new Carton(1.2,1.2,1.2,"softboard");
    //pBox = pCarton;
    pBox->showVolumn();
    //pCarton->showVolumn();
    //std::cout << "Box's volumn is ";
    //pBox->showVolumn();
    //delete pBox;
    //delete pCarton;
    return 0;
}
