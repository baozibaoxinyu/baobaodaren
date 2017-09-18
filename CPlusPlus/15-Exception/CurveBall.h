#ifndef CURVEBALL_H
#define CURVEBALL_H
#include <exception>
#include <string>
class CurveBall :public std::exception {
private:
	const char* message;
public:
	CurveBall(const char* theMessage) :message{ theMessage } {}
	virtual ~CurveBall() {}
	virtual const char* what() const noexcept override {
		return message;
	}
};
class TooManyException : std::exception {
private:
	const char* message;
public:
	TooManyException(const char* theMessage) :message{ theMessage } {}
	virtual ~TooManyException() {};
	virtual const char* what() const noexcept override {
		return message;
	}
};
#endif