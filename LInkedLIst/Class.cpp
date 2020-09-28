#include "Class.h"

#include <iostream>

template <typename T>
Class<T>::Class(const T& a)
{
	this->a = a;
	std::cout << "aaaaaaaa" << std::endl;
}
