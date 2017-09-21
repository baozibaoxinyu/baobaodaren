//using iterator
#include <numeric>
#include <iostream>
#include <iterator>

int main()
{
    double data[]{2.5,2.6,2.7,3.5,3.7};
    std::cout << "The array containers:\n";
    for(auto iter = std::begin(data);iter!= std::end(data);++iter)
	std::cout << *iter << " ";
    auto total = std::accumulate(std::begin(data),std::end(data),0.0);
    std::cout << "\nThe sum of the array elements is " << total <<std::endl;
    return 0;
}
