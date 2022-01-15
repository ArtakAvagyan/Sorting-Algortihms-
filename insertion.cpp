#include <iostream>
#include <iterator>
#include <vector>

#include "Utility.h"

void insertionSort(std::vector<int>&vec)
{
	for (int i = 1 ; i < vec.size() ; ++i)
	{
		int target = vec[i];
		int j = i-1;
		while (j >= 0 && vec[j] > target)
		{
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = target;
	}
}

int main()
{
	std::vector<int>vec{5,4,7,8,9,6,3,2,1,10,11,12};
	insertionSort(vec);
	for (int i = 0 ; i < vec.size() ; ++i)
		std::cout<< vec[i] << "  ";
	std::cout<<std::endl;

}
