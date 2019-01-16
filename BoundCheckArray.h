#ifndef  __BOUND_CHECK_ARRAY_H_
#define __BOUND_CHECK_ARRAY_H_

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}

public:
	BoundCheckArray(int len=1000);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};



template<typename T>
inline BoundCheckArray<T>::BoundCheckArray(int len) :arrlen(len)
{
	arr = new T[len];
}

template<typename T>
inline T & BoundCheckArray<T>::operator[](int idx)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
inline T BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
inline int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template<typename T>
inline BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] arr;
}

#endif