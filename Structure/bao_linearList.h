#ifndef BAO_LINEARLIST_H
#define BAO_LINEARLIST_H
#include "../../Char2_Exercise/Char2_Solu/bao_algorithm.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
namespace Bao {
	//创建一个线性表的抽象类
	template <typename T>
	class linearList {
	public:
		virtual ~linearList() {}
		//判断线性表是否为空，为空返回true，否则为false
		virtual bool empty() const = 0;
		//返回线性表的长度
		virtual int size() const = 0;
		//得到指定索引对应的值
		virtual T& get(int theIndex) const = 0;
		//得到线性表内第一次出现x的索引，如果没有返回-1
		virtual int indexOf(const T& theElement) const = 0;
		//删除索引为index的值，索引大于index的元素其索引-1
		virtual void erase(int theIndex) = 0;
		//把x插入线性表中索引为index的位置，索引大于index的元素其索引+1
		virtual void insert(int theIndex, const T& theElement) = 0;
		//从左至右输出线性表的元素
		virtual void output(std::ostream& out) const = 0;
	};
	//定义arrayList
	template <typename T>
	class arrayList : public linearList<T> {
	protected:
		//若index无效，则抛出异常
		void checkIndex(int theIndex) const;
		//存储线性表元素的一维数组
		T* elements;
		//一维数组的容量
		int arrayLength;
		//线性表的元素个数
		int listSize;
	public:
		//构造函数
		arrayList(int initialCapacity);
		arrayList(const arrayList<T>&);
		~arrayList() { delete[] elements; }

		bool empty() const override { return listSize == 0; }
		int size() const override { return listSize; }
		T& get(int theIndex) const override;
		int indexOf(const T& theElement) const;
		void erase(int theIndex);
		void insert(int theIndex, const T& theElement);
		void output(std::ostream& out) const;
		int capacity() const { return arrayLength; }
	};
	//arrayList的构造函数
	template <typename T>
	arrayList<T>::arrayList(int initialCapacity) {
		if (initialCapacity < 0) {
			std::ostringstream s;
			s << "Initial capacity = " << initialCapacity << " Must be > 0";
			throw illegalParameterValue(s.str());
		}
		arrayLength = initialCapacity;
		elements = new T[arrayLength];
		listSize = 0;
	}
	//arrayList的副本构造函数
	template <typename T>
	arrayList<T>::arrayList(const arrayList<T>& theList) {
		arrayLength = theList.arrayLength;
		listSize = theList.listSize;
		elements = new T[arrayLength];
		std::copy(theList.elements, theList.elements + listSize, element);
	}
	template <typename T>
	void arrayList<T>::checkIndex(int theIndex) const {
		if (theIndex < 0 || theIndex >= listSize) {
			std::ostringstream s;
			s << "index = " << theIndex << " size = " << listSize;
			throw illegalIndex(s.str());
		}
	}
	template <typename T>
	T& arrayList<T>::get(int theIndex) const {
		checkIndex(theIndex);
		return elements[theIndex];
	}
	template <typename T>
	int arrayList<T>::indexOf(const T& theElement) const {
		int theIndex = int(std::find(elements, elements + listSize, theElement) - elements);
		if (theIndex == listSize) return -1;
		else return theIndex;
	}
	template <typename T>
	void arrayList<T>::erase(int theIndex) {
		checkIndex(theIndex);
		std::copy(elements + theIndex + 1, elements + listSize, elements + theIndex);
		elements[--listSize].~T();
	}
	template <typename T>
	void arrayList<T>::insert(int theIndex, const T& theElement) {
		if (theIndex<0 || theIndex>listSize) {
			std::ostringstream s;
			s << "index = " << theIndex << " size = " << listSize;
			throw illegalIndex(s.str());
		}
		if (arrayLength == listSize) {
			changeLength1D(elements, arrayLength, 2 * arrayLength);
			arrayLength = 2 * arrayLength;
		}
		std::copy_backward(elements + theIndex, elements + listSize, elements + listSize + 1);
		elements[theIndex] = theElement;
		++listSize;
	}
	template <typename T>
	void arrayList<T>::output(std::ostream& out) const {
		std::copy(elements, elements + listSize, std::ostream_iterator<T>(out, " "));
	}
	template <typename T>
	std::ostream& operator<<(std::ostream& out, const arrayList<T>& x) {
		x.output(out);
		return out;
	}
}
#endif
