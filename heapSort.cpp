#include "heapSort.h"

#include <iostream>


template <typename T>
Heap<T>::Heap(T* tree ,const size_t length)
	:_tree(tree) , _length(length)
{
	_heapSize = _length;
}

template <typename T>
void Heap<T>::setArrey(T*tree , const size_t length)
{
	_tree = tree;
	_length = length;
	_heapSize = _length;
}

template <typename T>
void Heap<T>::setSize(const size_t length)
{
	_length = length;
	_heapSize = _length;
}

template <typename T>
T* Heap<T>::getArrey()const
{
	return _tree ;
}

template <typename T>
void Heap<T>::maxHeapify(const size_t pos)
{
	size_t l = nodeLeft(pos);
	size_t r = nodeRight(pos);
	size_t largest = pos;
	if ( _tree[largest] < _tree[l] && l < _heapSize ) { largest = l ;}
	if ( _tree[largest] < _tree[r] && l < _heapSize ) { largest = r ;}
	if (largest == pos ) { return;}
	std::swap(_tree[largest],_tree[pos]);
	maxHeapify(largest);
}

template <typename T>
void Heap<T>::buildMaxHeapify()
{
	for(int i = ((_heapSize / 2) + 1) ; i >= 0 ; --i)
	{
		maxHeapify(i);
	}
}

template <typename T>
size_t Heap<T>::nodeLeft(const size_t pos )const
{
	return (pos * 2)+1;
}

template <typename T>
size_t Heap<T>::nodeRight(const size_t pos )const
{
	return (pos * 2);
}

template <typename T>
size_t Heap<T>::nodeParent(const size_t pos )const
{
	return (pos / 2);
}

template <typename T>
void Heap<T>::heapSort()
{
	while(_heapSize > 1)
	{
		buildMaxHeapify();
		std::swap( _tree[0] , _tree[--_heapSize] );
	}
}

int main()
{
	int arr[33]{-11,5,8,9,7,4,6,3,1,5,8,9,7,8,4,5,6,2,1,5,56,6,2,4,5,5,2,5,2,1,-1,99};
	Heap<int> h ;
	h.setArrey(arr);
	h.setSize(33);
	h.heapSort();
	for(int i = 0 ; i < 33 ; ++i)
	{
		std::cout<< arr[i] << "  " ;
	}
	std::cout << std::endl;
}
