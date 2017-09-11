#include <iostream>
#include <iomanip>
#include <algorithm>

template <typename T>
T* changeLength1D(T a[],T oldLength,T newLength);
template <typename T>
void showArray1D(T a[],T newLength);
int main()
{
    int* a= new int[10]{1,2,3,4,5,6,7,8,9,10};
    int newlength = 9;
    a = changeLength1D(a,10,newlength);
    showArray1D(a,newlength);
    return 0;
}

template <typename T>
T* changeLength1D(T a[],T oldLength,T newLength){
    T* b = new T[newLength];
    for(int i{};i< std::min(oldLength,newLength);++i){
        b[i] = a[i];
    }
    delete [] a;
    return b;
}

template <typename T>
void showArray1D(T a[],T newLength){
    int perline{5};
    for(int i{};i< newLength;++i){
        std::cout<< std::setw(5) << a[i];
        if((i+1)%perline == 0) std::cout << std::endl;
    }
    std::cout<< std::endl;
}
