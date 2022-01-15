#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

#include "Utility.h"

void SelectionSort(std::vector<int>& vec)
{
	for (int i = 0 ; i < vec.size() ; ++i)
	{
		int min = i ;
		for (int j = i+1 ; j < vec.size() ; ++j)
		{
			if (vec[min] > vec[j])
			{ 
				min = j;
			}
		}
		Util::swap(vec[min],vec[i]);
	}
}
template <typename T>
void SelectionSort(T beg , T end)
{
	while (beg != end)
	{
		auto min = beg;
		for (auto i = std::next(beg) ; i != end ; ++i)
		{
			if (*min > *i)
			{
				min = i ;
			}
		}
		Util::swap(*min,*beg);
		beg++;
	}
}

int main()
{
	std::vector<int>vec {5,6,7,8,9,1,2,3,4};
	SelectionSort(vec.begin(),vec.end());
	std::copy(vec.begin(),vec.end(),std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;

}
