//Ex1_02.cpp
//using stream iterators
#include <iostream>
#include <iterator>
#include <numeric>
using std::cout;
using std::endl;
int main()
{
    cout<< "Enter numeric values separated by space and enter Ctrl+ Z to end"
        <<endl;
    cout<< "\nThe sum of the values you entered is "
        << std::accumulate(std::istream_iterator<double>(std::cin),
			std::istream_iterator<double>(),0.0)
	<< endl;
}




