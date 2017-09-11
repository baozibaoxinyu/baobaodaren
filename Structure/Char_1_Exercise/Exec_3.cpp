#include <iostream>

template <typename T>
void fill(T a[],size_t start,size_t end,T value);
template <typename T>
void showArray(T a[],size_t number);

int main()
{
    int a [10] = {1,3,4};
    showArray(a,10);
    size_t start{},end {5};
    int value = 10;
    fill(a,start,end,value);
    std::cout<< "array a' value is "<< std::endl;
    showArray(a,10);
}

template <typename T>
void fill(T a[],size_t start,size_t end,T value){
    for(size_t i {start};i< end;++i){
        a[i] = value;
    }
}

template <typename T>
void showArray(T a[],size_t number){
    size_t perline{5};
    for(size_t i{};i< number;++i){
        std::cout<< a[i]<< " ";
        if((i+1)%perline == 0){
            std::cout<<std::endl;
        }
    }
}
