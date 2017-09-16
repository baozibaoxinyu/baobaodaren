/******************************************
 *使用copy算法，sort算法，prev_permutation
 *算法进行数组的逆向排列
 ******************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
template <typename T>
void pre_permutation(T list[],int k,int m){
    std::sort(list+k,list+m+1);
    T a[m];
    for(int i = k;i<=m;++i)
        a[m-i]= list[i];
    for(int i = k;i<=m;++i)
        list[i]= a[i];
    do{
        copy(list+k,list+m+1,std::ostream_iterator<T>(std::cout,""));
        std::cout<<std::endl;
    }while(std::prev_permutation(list+k,list+m+1));
}

int main()
{
    char a[]= {'b','a','c','d'};
    pre_permutation(a,0,3);
    return 0;
}
