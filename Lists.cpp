

#include "list.h"
#include <iostream>
#include <string>
#include <vector>
using namespace lab618;

int main()
{
	std::cout << "Test CSingleLinkedList: " << '\n';
	CSingleLinkedList<MyStruct> list1; 
	list1.pushBack({ 1,1.2 });
	list1.pushBack({ 3,4.2 });
	list1.pushBack({ 5,6.3 });
	list1.pushBack({ 7, 7.2 });
	list1.pushBack({ 8,8.2 });
	std::cout << list1.getSize() << '\n';
	list1.popFront();
	list1.popFront();
	list1.popFront();
	std::cout << list1.getSize() << '\n';
	list1.pushBack({ 666,6.6 });
	list1.pushBack({ 7777,7.7 });
	list1.pushBack({ 8888,8.8 });
	list1.pushFront({ 023,-123.2 });
	list1.pushFront({ -1,-1.2 });
	std::cout << list1.getSize() << '\n';
	std::cout << list1.begin().getData().a << ' ' << list1.begin().getData().b << '\n';
	CSingleLinkedList<MyStruct>::CIterator it = list1.begin();
	//++it;
	//list1.erase(it);
	//list1.clear();

	if (*it)
	{
		std::cout << "Hello world";
	}

	std::cout << '\n' << "Test CDualLinkedList: " << '\n';




	CDualLinkedList<std::string> list3;
	std::vector<std::string> vec_str{ "AAA","BBB","CCC","DDD","EEE","FFF","XXXX","ZZZZ" };
	for (int i = 0; i < vec_str.size(); i++)
	{
		list3.pushBack(vec_str[i]);
	}


	for (CDualLinkedList < std::string > ::CIterator iter = list3.begin(); iter.isValid(); ++iter) {

		std::cout << iter.getData() << ' ';
	}


	std::cout << list3.getSize() << '\n';
	std::cout << list3.begin().getData() << ' ' << '\n';

	CDualLinkedList<std::string>::CIterator iter1 = list3.begin();

	list3.eraseAndNext(iter1);

	list3.popFront();
	list3.popBack();

	for (CDualLinkedList<std::string>::CIterator iter4 = list3.begin(); iter4.isValid(); ++iter4) {
		list3.erase(iter4);
	}

	list3.clear();



	return 0;
}