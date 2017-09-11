#include <iostream>
template <typename T>
int mismatch(T a[],T b[],size_t number);

int main()
{
    int a[10]= {1,2,3,4,5,6,7,8,9,10};
    int b[10]= {1,2,3,4,6,6,5,1,2,3};
    std::cout<< "(a != b)'s index is "<< mismatch(a,b,10)<< std::endl;
    return 0;
}

template <typename T>
int mismatch(T a[],T b[],size_t number){
    size_t count{1};
    size_t index{};
    for(size_t i{};i<number;++i){
        ++count;
        if(a[i]!= b[i]){
            index = i;
            break;
        }
    }
    if(count==number){
        return -1;
    }
    else
        return index;
}
