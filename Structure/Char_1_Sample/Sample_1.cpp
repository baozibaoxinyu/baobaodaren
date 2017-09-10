#include <iostream>
#include <vector>
#include "Currency.h"

int main()
{
	std::vector<Currency> currency{
		Currency(plus,3,50),
		Currency(),
		Currency(),
		Currency() };
	currency[1].setValue(plus, 4, 20);
	currency[2].setValue(-6.26);
	currency[3] = currency[3] + currency[2];
	for (auto& curr : currency) {
		std::cout << curr;
	}
	currency[0] += currency[1];
	currency[2] = currency[1] + currency[3] + currency[2];
	for (auto& curr : currency) {
		std::cout << curr;
	}
	std::cout << "attempting to initialize with cents = 100" << std::endl;
	try { 
		currency.push_back(Currency());
		currency[4].setValue(plus, 10, 101);
	}
	catch (illegalParameterValue e) {
		std::cout << "Caught thrown excetion" << std::endl;
		e.outputMessage();
	}
	return 0;
}


