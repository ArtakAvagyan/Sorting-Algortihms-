#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

std::vector<int>::iterator Partition (std::vector<int>::iterator start , std::vector<int>::iterator end)
{
	int& it = *start;
	std::vector<int>::iterator i = start;
	std::vector<int>::iterator j = end;
	while (i < j)
	{
	       	while (*i <= it){++i;}
		while (*j > it){--j;}
		if (i < j) { std::swap(*i,*j); }
	}
	std::swap(it,*j);
	return j;
}

void quickSort (std::vector<int>::iterator start , std::vector<int>::iterator end)
{
	if (start < end)
	{
		std::vector<int>::iterator it = Partition(start,end);
		quickSort (start,it-1);
		quickSort (it+1,end);
	}
}
int main()
{
	std::vector<int>vec{1,7,8,4,9,14};
	quickSort(vec.begin(),vec.end()-1);
	for (const auto& it : vec)
	{
		std::cout << it <<"  ";
	}
	std::cout << std::endl;
}
