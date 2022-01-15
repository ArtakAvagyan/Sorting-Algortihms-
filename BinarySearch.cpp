#include <iostream>
#include <vector>
#include <iterator>
#include <exception>


template <typename iter , typename T>
iter BinarySearch(iter beg , iter end , const T& key)
{
	if(beg > end) {throw std::invalid_argument{"aaaqaa"} ;}
	auto it = std::next( beg , (std::distance(beg,end)/2));
	if (*it == key) { return it; }
	else if (*it < key) { return BinarySearch( std::next(it),end, key ); }
	else if (*it > key) { return BinarySearch( beg,std::prev(it),key);}
	return {};
}

int main()
{
	std::vector<int>vec{1,2,3,4,5,6,7,8,9,10};
	auto it = vec.begin();
	try{
		it = BinarySearch(vec.begin(),vec.end()-1,18);
	}
	catch(std::invalid_argument msg)
	{
		std::cerr<< msg.what()<< std::endl;
		return -1;
	}	
	std::cout << *it << std::endl;
	return 0 ;

}
