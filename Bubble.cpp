#include <iostream>
#include <vector>
#include <iterator>

#include "Utility.h"

void bubbleSort(std::vector<int>&);
template < typename T >
void bubbleSort( T beg , T end )
{
	auto k = beg;
	while(beg != end)
	{
		bool isSort = true ;
		for(auto i = k ; i != end ; ++i)
		{
			if(*i > *std::next(i))
			{
				Util::swap(*i,*std::next(i)) ;
				isSort = false ;
			}
		}
		if (isSort) {break;}
		beg++;
	}
}

int main()
{
	std::vector<int>vec{8,6,5,4,7,8,61,4,5};
	bubbleSort(vec.begin(),vec.end());
	for(int i = 0 ; i < vec.size() ; ++i)
	{
		std::cout<< vec[i] << "  ";
	}
	std::cout<<std::endl;
	return 0;
}


void bubbleSort(std::vector<int>& vec)
{
	for (int i = 0 ; vec.size() ; ++i )
	{
		bool isSort = true ;
		for ( int j = 0 ; j < vec.size() ; ++j )
		{
			if ( vec[i] > vec[i+1])
			{
				Util::swap<int>(vec[i],vec[i+1]);
				isSort = false ;
			}
		}
		if (isSort) {break;}
	}
}

