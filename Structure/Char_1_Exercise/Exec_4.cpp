#include <iostream>

template <typename T>
T inner_product(T a[],T b[],size_t n);

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[10] = {2,4,6,8,10,12,14,16,18,20};
    std::cout<< "result is " << inner_product(a,b,1)<< std::endl;
}

template <typename T>
T inner_product(T a[],T b[],size_t n) {
    T sum{};
    for(size_t i{};i<n;++i){
        sum+= a[i]*b[i];
    }
   return sum;
}
