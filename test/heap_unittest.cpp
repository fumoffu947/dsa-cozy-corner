#include "heap.h"
#include "gtest/gtest.h"
#include <functional>
#include <iostream>

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
	h.insert(20);
	h.insert(1);
	h.insert(32);
	h.insert(88);
	h.insert(92);
	h.insert(2);
	h.insert(26);
	h.insert(36);
	h.insert(12);
	h.insert(92);
	h.insert(48);
	h.insert(43);

	ASSERT_EQ(h.removeFirst(), 1);
	ASSERT_EQ(h.removeFirst(), 2);
	ASSERT_EQ(h.removeFirst(), 4);
	ASSERT_EQ(h.removeFirst(), 9);
	ASSERT_EQ(h.removeFirst(), 12);
	ASSERT_EQ(h.removeFirst(), 20);
	ASSERT_EQ(h.removeFirst(), 26);
	ASSERT_EQ(h.removeFirst(), 32);
	ASSERT_EQ(h.removeFirst(), 33);
	ASSERT_EQ(h.removeFirst(), 36);
	ASSERT_EQ(h.removeFirst(), 43);
	ASSERT_EQ(h.removeFirst(), 48);
	ASSERT_EQ(h.removeFirst(), 88);
	ASSERT_EQ(h.removeFirst(), 92);
	ASSERT_EQ(h.removeFirst(), 92);
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

	h.insert(5);
	h.insert(4);
	h.insert(1);

	ASSERT_EQ(h.remove(2), 4);
	ASSERT_EQ(h.remove(1), 5);
	ASSERT_EQ(h.remove(0), 1);
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

class TestClass {
public:
	int value = 0;
};

bool testClassComparer(TestClass a, TestClass b) {
	return a.value < b.value;
}
/*
This will test so a standalone function will work as comparer with a class.
*/
TEST(HeapTest, NonStandardComparer) {
	Heap<TestClass, std::function<bool(TestClass, TestClass)>> h(testClassComparer);

	TestClass a;
	a.value = 1;
	TestClass b;
	b.value = 9;
	TestClass c;
	c.value = 20;
	TestClass d;
	d.value = 44;

	h.insert(c);
	h.insert(a);
	h.insert(d);
	h.insert(b);

	ASSERT_EQ(h.removeFirst().value, 1);
	ASSERT_EQ(h.removeFirst().value, 9);
	ASSERT_EQ(h.removeFirst().value, 20);
	ASSERT_EQ(h.removeFirst().value, 44);
}