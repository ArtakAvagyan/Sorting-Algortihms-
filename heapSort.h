#include <iostream>

#ifndef HEAPSORT_H
#define HEAPSOTR_H
/*Heap sort is a comparison-based sorting technique based on Binary Heap data structure. 
 * It is similar to selection sort where we first find the minimum element and place the minimum element at the beginning.
 * We repeat the same process for the remaining elements.
 * Quick is a O (n * lg(n));
 */
template<typename T>
class Heap
{
public:
	Heap() = default ;
	~Heap() = default ;
	Heap(const Heap&) = delete ;
	Heap(T*,const size_t);
public:
	void setArrey(T* , const size_t length = 0);
	void setSize(const size_t);
	T* getArrey()const;
	void heapSort();
	void buildMaxHeapify();
	void maxHeapify(const size_t);
private:
	size_t nodeLeft(const size_t)const;
	size_t nodeRight(const size_t)const;
	size_t nodeParent(const size_t)const;
private:
	T* _tree;
	size_t _length;
	size_t _heapSize;
};

#endif /*HEAPSORT_H*
