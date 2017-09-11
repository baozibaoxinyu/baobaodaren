#include <iostream>
template <typename T>
bool is_sorted(T a[],size_t number);

int main()
{
    int a[10]{1,1,1,1,1,1,1,1,1,1};
    int b[10]{2,2,1,4,2,4,2,4,6,2};
    if(is_sorted(a,10)) std::cout<<"array a is sorted" << std::endl;
    else std::cout<<"array b is not sorted" << std::endl;
    if(is_sorted(b,10)) std::cout<<"array b is sorted" << std::endl;
    else std::cout<<"array b is not sorted" << std::endl;
    return 0;
}

template <typename T>
bool is_sorted(T a[],size_t number){
    bool ascending {true};
    bool descending {true};
    if(a[1]-a[0]>= 0)
        for(size_t i{1};i<number;++i){
            if(a[i]-a[i-1]< 0) {
                ascending = false;
                break;
            }
        }
    if(a[1]-a[0]<= 0)
        for(size_t i{1};i< number;++i){
            if(a[i]-a[i-1]> 0){
                descending = false;
                break;
            }
        }
    if(ascending&&descending) return true;
    else return false;
}
