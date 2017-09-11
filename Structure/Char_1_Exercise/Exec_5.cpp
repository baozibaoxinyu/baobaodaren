#include <iostream>
#include <iomanip>

template <typename T>
void iota(T a[],T value,size_t n);
template <typename T>
void showArray(T a[],size_t number){
    size_t perline{5};
    for(size_t i{};i< number;++i){
        std::cout<< std::setw(5) << a[i]<< " ";
        if((i+1)%perline == 0) std::cout<<std::endl;
    }
}

int main()
{
    int a[10]{};
    int value {5};
    double b[10]{};
    double value1 {3.4};
    iota(a,value,10);
    iota(b,value1,10);
    std::cout<<"array a's result is "<< std::endl;
    showArray(a,10);
    std::cout<<"array b's result is "<< std::endl;
    showArray(b,10);
    return 0;
}

template <typename T>
void iota(T a[],T value,size_t n){
    for(size_t i{};i< n ;++i){
        a[i] = value + i;
    }
}
