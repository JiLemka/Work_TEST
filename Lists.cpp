#include "list.h"
#include <iostream>

using namespace lab618;

int main()
{
	std::cout << "Test CSingleLinkedList: " << '\n';
	CSingleLinkedList<int> list1;  // сделать так что бы изначально создавался с 0
	list1.pushBack(11111);
	list1.pushBack(22222);
	list1.pushBack(3333);
	list1.pushBack(44444);
	list1.pushBack(5555);
	std::cout << list1.getSize() << '\n';
	list1.popFront();
	list1.popFront();
	list1.popFront();
	std::cout << list1.getSize() << '\n';
	list1.pushBack(666);
	list1.pushBack(7777);
	list1.pushBack(8888);
	list1.pushFront(0);
	list1.pushFront(-1);
	std::cout << list1.getSize() << '\n';
	std::cout << *list1.begin() << '\n';
	CSingleLinkedList<int>::CIterator it = list1.begin();
	++it;
	list1.erase(it);
	list1.clear();


	std::cout << '\n' << "Test CDualLinkedList: " << '\n';

	CDualLinkedList<int> list2;
	list2.pushBack(11111);
	list2.pushBack(22222);
	list2.pushBack(3333);
	list2.pushBack(44444);
	list2.pushBack(5555);
	std::cout << list2.getSize() << '\n';
	list2.popFront();
	list2.popFront();
	list2.popFront();
	std::cout << list2.getSize() << '\n';
	list2.pushBack(666);
	list2.pushBack(7777);
	list2.pushBack(8888);
	list2.pushFront(0);
	list2.pushFront(-1);
	std::cout << list2.getSize() << '\n';
	std::cout << *list2.begin() << '\n';
	CDualLinkedList<int>::CIterator it12 = list2.begin();
	++it12;
	list2.erase(it12);
	CDualLinkedList<int>::CIterator it11 = list2.begin();
	list2.eraseAndNext(it11);
	std::cout << list2.popFront() << '\n';
	std::cout << list2.popBack() << '\n';
	list2.clear();



	return 0;
}