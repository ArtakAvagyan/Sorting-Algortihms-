#include <iostream>
#include <algorithm>


#ifndef UTILITY_H
#define UTILITY_H

namespace Util
{
	template <typename T>
	void swap(T& a , T&b)
	{
		T tmp = std::move(a);
		a = std::move(b);
		b = std::move(tmp);
	}

};

#endif /*UTILITY_H*/
