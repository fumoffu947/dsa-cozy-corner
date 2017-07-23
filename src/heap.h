#pragma once
#include <algorithm>

template <typename T, class Compare = std::less<T>>
class Heap {
private:
	// The total size of the array containing the elements
	int array_size = 2;
	// The number of elements in the array
	int element_count = 0;
	// The continer for the given elements
	T* heap_array;
	// The comparator used to sort the heap in the given way, acoording to the Comparer
	Compare cmp;

	/*
	Calculates the index of the left child given the index.
	Returns -1 if there is no left child.
	@param index: The index to find the left child to.
	@return Returns the index of the right child, else -1 if there is no left child.
	*/
	int leftChild(int index);
	/*
	Calculates the index of the right child given the index.
	@param index: The index to find the right child to.
	@return Returns the index of the right child, else -1 if there is no right child.
	*/
	int rightChild(int index);
	/*
	Calculates the index of the parent given the index.
	@param index: The index to find the parent of.
	@return Returnes the index of the parent, -1 if there is no parent.
	*/
	int parent(int index);
	/*
	Calculates if the given index is a leaf.
	If the index is more then half the nodes, it is a leaf.
	@param index: The index to check if it is a leaf.
	@return Will return true if it is a leaf-index.
	*/
	bool isLeaf(int index);
	/*
	Given the elements in the array it will make sure that the array hase the right
	structure of a heap.
	*/
	void buildHeap();
	/*
	This function will shift an element downward to the right position given an index.
	@param index: The index of the value to shift to the right place downward.
	@return A bool to tell if the value was shifted.
	*/
	bool shiftElem(int index);

public:
	Heap();
	~Heap();
	int size();
	/*
	This fucntion will insert a value into the heap and move it to the right position
	@param value: The value to insert into the array.
	*/
	void insert(T value);
	/*
	Will remove the first element in the list, highest/ lowet given the cmp funciton.
	@return The first value in the list.
	*/
	T removeFirst();
	/*
	This function will remove the value att the given index and then make sure the array
	is a heap again.
	@param index: The index of the value to remove.
	@return The value at the given index.
	*/
	T remove(int index);
};

/* --------------------------------------------- ##
* ---------------------------------------------*/

template<typename T, class Compare>
Heap<T, Compare>::Heap() {
	heap_array = new T[array_size];
}

template<typename T, class Compare>
inline Heap<T, Compare>::~Heap() {
	delete[] heap_array;
}

template<typename T, class Compare>
int Heap<T, Compare>::leftChild(int index) {
	int childIndex = index * 2 + 1;
	if (childIndex < element_count) {
		return childIndex;
	}
	return -1;
}

template<typename T, class Compare>
int Heap<T, Compare>::rightChild(int index) {
	int childIndex = index * 2 + 2;
	if (childIndex < element_count) {
		return childIndex;
	}
	return -1;
}

template<typename T, class Compare>
int Heap<T, Compare>::parent(int index) {
	if (index = 0) return 0;
	return (index-1)/2;
}

template<typename T, class Compare>
bool Heap<T, Compare>::isLeaf(int index) {
	return (index >= element_count / 2) && (index < element_count);
}

template<typename T, class Compare>
void Heap<T, Compare>::buildHeap() {
	for (int i = (element_count / 2) - 1; i >= 0; i--) {
		shiftElem(i);
	}
}

template<typename T, class Compare>
bool Heap<T, Compare>::shiftElem(int index) {
	if (index < 0 || index > element_count) return false;
	while (!isLeaf(index)) {
		int childIndex = leftChild(index);
		// The left child is either lesser or grater than the right child so check againt that child insted
		if ((childIndex < (element_count - 1)) && !cmp(heap_array[childIndex], heap_array[childIndex + 1])) childIndex++;
		// If the current index is greater then or lesser then the child, given the comparer, then dont swap.
		if (cmp(heap_array[index], heap_array[childIndex])) return false;
		std::swap(heap_array[index], heap_array[childIndex]);
		index = childIndex;
	}
	return true;
}

template<typename T, class Compare>
int Heap<T, Compare>::size() {
	return element_count;
}

template<typename T, class Compare>
void Heap<T, Compare>::insert(T value) {
	// If the array is not large enough then make a new one that fits the elements (but lager then that)
	if (element_count == array_size) {
		T* tmp_array = new T[array_size * 2];
		std::copy(heap_array, heap_array + element_count, tmp_array);
		heap_array = tmp_array;
	}
	// Get the last element index and then use post-increment
	int current_index = element_count++;
	heap_array[current_index] = value;
	// Let the element bubble upp as far it can, to the right place
	while ((current_index != 0) && cmp(heap_array[current_index], heap_array[parent(current_index)])) {
		std::swap(heap_array[current_index], heap_array[parent(current_index)]);
		current_index = parent(current_index);
	}
}

template<typename T, class Compare>
T Heap<T, Compare>::removeFirst() {
	if (element_count == 0) return NULL;
	// Swap the last element with the first and then make sure it is a heap again
	std::swap(heap_array[0], heap_array[--element_count]);
	if (element_count != 0) {
		shiftElem(0);
	}
	return heap_array[element_count];
}

template<typename T, class Compare>
T Heap<T, Compare>::remove(int index) {
	// If the index is outside of the element_count return null
	if (index < 0 || index >= element_count) return NULL;
	// If the element is the last then no shifting is needed
	if (index == element_count - 1) element_count--;
	else {
		std::swap(heap_array[index], heap_array[--element_count]);
		// Shift the element uppward untill it cant move upp more
		while ((index > 0) && cmp(heap_array[index], heap_array[parent(index)])) {
			std::swap(heap_array[index], heap_array[parent(index)]);
			index = parent(index);
		}
		// Shift the element to the right place downward
		// (If the element did not move)
		if (index != 0) shiftElem(index);
	}
	return heap_array[element_count];
}
