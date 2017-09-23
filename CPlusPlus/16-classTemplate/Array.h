#ifndef ARRAY_H
#define ARRAY_H
#include <exception>
#include <iostream>
#include <string>
template <typename T>
class Array {
private:
	T* elements;
	size_t size;
public:
	explicit Array<T>(size_t arraySize);	//Constructor
	Array<T>(const Array<T>& array);		//Copy Constructor
	~Array();						//Destructor
	T& operator[](size_t index);	//Subscript operator
	const T& operator[](const size_t index) const;	//Subscript operator-const operator
	Array<T>& operator=(const Array<T>& rhs);		//Assignment operator
};
//Define constructor
template <typename T>
Array<T>::Array(size_t arraySize) try :size{ arraySize }, elements{ new T[arraySize] }
{}
catch (std::bad_alloc& ) {
	std::cerr << "Memory allocation failed for Array object.\n";
}

template <typename T>
Array<T>::Array(const Array<T>& array) try :size{ array.size }, elements{ new T[array.size] }
{
	for (size_t i{}; i < size; ++i) {
		elements[i] = array.elements[i];
	}
}
catch (std::bad_alloc& ) {
	std::cerr << "Memory allocation failed for Array object.\n";
}

template <typename T>
Array<T>::~Array() {
	delete[] elements;
}

template <typename T>
inline T& Array<T>::operator[](size_t index) {
	if (index >= size) throw std::out_of_range{ ("Index too large:") +
		std::to_string(index) };
	return elements[index];
}

template <typename T>
inline const T& Array<T>::operator[](const size_t index) const {
	if (index >= size) throw std::out_of_range{ ("Index too large:") +
		std::to_string(index) };
	return elements[index];
}

template <typename T>
inline Array<T>& Array<T>::operator=(
	const Array& rhs)
try {
	if (&rhs != this) {
		if (elements)
			delete[] elements;
		size = rhs.size;
		elements = new T[size];
		for (size_t i{}; i < size; ++i)
			elements[i] = rhs.elements[i];
	}
	return *this;
}
catch (std::bad_alloc&) {
	std::cerr << "Memory allocation failed for Array object.\n";
}
#endif
