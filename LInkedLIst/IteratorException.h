#pragma once
#include <stdexcept>

class IteratorException: public std::out_of_range
{
public:

	explicit IteratorException(const char* _Message)
		: out_of_range(_Message)
	{
	}
};
