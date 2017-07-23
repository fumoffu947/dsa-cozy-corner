#include "heap.h"
#include "gtest/gtest.h"
#include <functional>

/*
This file will include all the tests for the heap, not the versions that use the heap
for other purposes.
*/

/*
This test will check if the heap can sort values with the standard comparer.
*/
TEST(HeapTest, LesserComparer) {
	Heap<int> h;
	h.insert(9);
	h.insert(4);
	h.insert(33);

	ASSERT_EQ(h.removeFirst(), 4);
	ASSERT_EQ(h.removeFirst(), 9);
	ASSERT_EQ(h.removeFirst(), 33);
}

/*
This test will check if insert works, and removeFirst for one element.
*/
TEST(HeapTest, Insert) {
	Heap<int> h;

	h.insert(1);

	ASSERT_EQ(h.removeFirst(), 1);
}

/*
This will check if remove will work for a given index.
*/
TEST(HeapTest, Remove) {
	Heap<int> h;

	h.insert(5);
	h.insert(4);
	h.insert(1);

	ASSERT_EQ(h.remove(1), 5);
	ASSERT_EQ(h.removeFirst(), 1);
	ASSERT_EQ(h.removeFirst(), 4);
}

/*
This test will check so the size will he correct for the heap.
*/
TEST(HeapTest, Size) {
	Heap<int> h;

	h.insert(5);
	h.insert(4);
	h.insert(1);

	ASSERT_EQ(h.size(), 3);
	ASSERT_EQ(h.removeFirst(), 1);
	ASSERT_EQ(h.size(), 2);
	ASSERT_EQ(h.removeFirst(), 4);
	ASSERT_EQ(h.size(), 1);
	ASSERT_EQ(h.removeFirst(), 5);
	ASSERT_EQ(h.size(), 0);
	ASSERT_EQ(h.removeFirst(), NULL);
	ASSERT_EQ(h.size(), 0);
}

/*
This will test if other standard comparer works with remove and the right orded.
*/
TEST(HeapTest, Greater) {
	Heap<int, std::greater<int>> h;

	h.insert(1);
	h.insert(4);
	h.insert(5);
	h.insert(10);

	ASSERT_EQ(h.remove(1), 5);
	ASSERT_EQ(h.removeFirst(), 10);
	ASSERT_EQ(h.removeFirst(), 4);
	ASSERT_EQ(h.removeFirst(), 1);
}