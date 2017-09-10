/*
这里定义了一个货币类型Currency，由三个类型组成，符号，美元，美分
还有一些实现的操作：
1，给成员赋值
2，确定成员值
3，两个对象相加
4，增加成员的值
5，输出
*/
#ifndef CURRENCY_H
#define CURRENCY_H
//define signType to represent ths sign of currency
#include <iostream>
#include <string>
enum signType {plus,minus};

class Currency {
private:
	signType sign{plus};
	unsigned long dollars{};
	unsigned int cents{};
public:
	Currency(signType theSign, unsigned long theDollars, unsigned int theCents) :
		sign{ theSign }, dollars{ theDollars }, cents{ theCents } {}
	Currency() {}
	~Currency() {}

	void setValue(signType, unsigned long, unsigned int);
	void setValue(double);

	signType getSign() const{ return sign; }
	unsigned long getDollars() const { return dollars; }
	unsigned int getCents() const { return cents; }
	
	Currency& operator+(const Currency& currency)  {}
	Currency& operator+=(const Currency& currency)  {}
	friend std::ostream& operator<<(std::ostream& stream, const Currency& currency) ;
};
void Currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
	if (theCents > 99)
		throw illegalParameterValue("Cents shoule be < 100");

	sign = theSign;
	dollars = theDollars;
	cents = theCents;
}

class illegalParameterValue {
private:
	std::string message{ "Illegal parameters value" };
public:
	illegalParameterValue(char* theMessage) :message{ theMessage } {}
	illegalParameterValue() {}
	void outputMessage(){
		std::cout << message << std::endl;
	}
};

void Currency::setValue(double theAmount) {
	if (theAmount < 0) {
		sign = minus;
		theAmount = -theAmount;
	}
	else {
		sign = plus;
	}
	dollars = static_cast<unsigned long>(theAmount);
	cents = static_cast<unsigned int>((theAmount + 0.001 - dollars) * 100);
}

Currency& Currency::operator+(const Currency& currency) {
	long a1{}, a2{}, a3{};
	a1 = this->dollars * 100 + this->cents;
	a2 = currency.dollars * 100 + currency.cents;
	if (this->sign == minus) a1 = -a1;
	if (currency.sign == minus) a2 = -a2;
	a3 = a1 + a2;

	if (a3 < 0) {
		this->sign = minus;
		a3 = -a3;
	}
	else this->sign = plus;

	this->dollars = a3 / 100;
	this->cents = a3 - this->dollars * 100;
	return *this;
}

Currency& Currency::operator+=(const Currency& currency) {
	*this = *this + currency;
	return *this;
}

inline std::ostream& operator<<(std::ostream& stream, const Currency& currency) {
	if (currency.sign == plus) {
		stream << "+$" << currency.dollars << "dollars" << currency.cents
			<< "cents\n";
	}
	if (currency.sign == minus) {
		stream << "-$" << currency.dollars << "dollars" << currency.cents
			<< "cents\n";
	}
}
#endif