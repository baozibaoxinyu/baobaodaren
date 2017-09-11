#ifndef CURRENCYOVERLOAD_H
#define CURRENCYOVERLOAD_H
#include <iostream>
#include <string>
enum signType { plus, minus };
class Currency {
private:
	double amount{};
	signType sign = plus;
	unsigned long dollars{};
	unsigned int cents{};
public:
	//设置构造函数
	Currency(signType theSign, unsigned long theDollars, unsigned int theCents) :
		sign{ theSign }, dollars{ theDollars }, cents{ theCents } {
		setValue(theSign, theDollars, theCents);
	}
	Currency(double theAmount) :amount{ theAmount } {
		setValue(theAmount);
	}
	Currency(const Currency& currency) {
		amount = currency.amount;
		dollars = currency.dollars;
		cents = currency.cents;
		sign = currency.sign;
	}
	Currency() {}
	~Currency() {}
	//设置成员值
	void setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
		sign = theSign;
		dollars = theDollars;
		cents = theCents;
		if (sign == minus) {
			amount = -(double(dollars) + double(cents) / 100.0);
		}
		else {
			amount = double(dollars) + double(cents) / 100.0;
		}
	}
	void setValue(double theAmount) {
		amount = theAmount;
		if (amount < 0) {
			sign = minus;
			theAmount = -theAmount;
		}
		else sign = plus;
		dollars = static_cast<unsigned long>(theAmount);
		cents = static_cast<unsigned int>((theAmount + 0.01 - dollars) * 100);
	}
	//获取成员值
	signType getSign() {
		return sign;
	}
	unsigned long getDollars() {
		return dollars;
	}
	unsigned int getCents() {
		return cents;
	}
	double getAmount() {
		return amount;
	}
	//运算符重载 += + - * / % << >>
	Currency& operator+=(const Currency& currency);
	Currency operator+(const Currency& currency) {
		return Currency(*this += currency);
	}
	Currency operator-(const Currency& currency);
	Currency operator*(double x);
	Currency operator%(double x);
	Currency operator/(double x);
	friend std::ostream& operator<<(std::ostream& stream, const Currency& currency);
	friend std::istream& operator >> (std::istream& stream, Currency& currency);
};
inline Currency& Currency::operator+=(const Currency& currency) {
	amount = amount + currency.amount;
	long a1{}, a2{}, a3{};
	a1 = dollars * 100 + cents;
	if (sign == minus) a1 = -a1;
	a2 = currency.dollars * 100 + currency.cents;
	if (currency.sign == minus) a2 = -a2;
	a3 = a1 + a2;
	if (a3 < 0) {
		sign = minus;
		a3 = -a3;
	}
	dollars = static_cast<unsigned long>(a3 / 100);
	cents = static_cast<unsigned int>(a3 - dollars * 100);
	return *this;
}
inline Currency Currency::operator-(const Currency& currency) {
	amount = amount - currency.amount;
	long a1{}, a2{}, a3{};
	a1 = dollars * 100 + cents;
	if (sign == minus) a1 = -a1;
	a2 = currency.dollars * 100 + currency.cents;
	if (currency.sign == minus) a2 = -a2;
	a3 = a1 - a2;
	if (a3 < 0) {
		sign = minus;
		a3 = -a3;
	}
	dollars = static_cast<unsigned long>(a3 / 100);
	cents = static_cast<unsigned int>(a3 - dollars * 100);
	return Currency(*this);
}
inline Currency Currency::operator*(double x) {
	amount = amount*(x);
	return Currency(amount);
}
inline Currency Currency::operator%(double x) {
	amount = amount*(x) / 100.0;
	return Currency(amount);
}
inline Currency Currency::operator/(double x) {
	amount = amount / x;
	return Currency(amount);
}
inline std::ostream& operator<<(std::ostream& stream, const Currency& currency) {
	if (currency.sign == minus)stream << "-$" << -currency.amount << std::endl;
	else stream << "+$" << currency.amount << std::endl;
	return stream;
}
inline std::istream& operator >> (std::istream& stream, Currency& currency) {
	
	stream >> currency.amount;
	currency.setValue(currency.amount);
	return stream;
}
#endif
