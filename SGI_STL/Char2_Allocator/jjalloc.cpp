//file: 2jjalloc.cpp
#include "jjalloc.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int ia[5] = {1,2,3,4,5};
    vector<int,JJ::allocator<int>> iv(ia,ia+5);
    for(size_t i{};i<iv.size();++i){
        cout << iv[i] <<endl;
    }
    cout << endl;
    return 0;
}
