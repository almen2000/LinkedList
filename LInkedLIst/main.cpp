#include <iostream>
#include <list>
#include "Tools.h"

using namespace tools;
using namespace std;

int main()
{
	LinkedList<int> my_list;
	// calling push_back() method
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.push_back(4);
	// calling push_front() method
	my_list.push_front(10);
	my_list.push_front(11);
	my_list.push_front(12);
	// print linked list
	for (LinkedList<int>::value_type it : my_list)
	{
		cout << it << ' ' << flush;
	}
	cout << endl << endl << endl;
	// calling front() method
	cout << my_list.front() << endl;
	// calling back() method
	cout << my_list.back() << endl;
	// calling get() method
	cout << my_list.get(0) << endl;
	cout << my_list.get(6) << endl;
	// calling erase() method
	my_list.erase(my_list.begin());
	// calling begin() method witch returns iterator
	auto iterator1 = my_list.begin();
	auto it = my_list.erase(my_list.begin() + 3);
	// calling insert() method
	my_list.insert(it, 7);
	cout << endl << endl << endl;
	for (LinkedList<int>::value_type it : my_list)
	{
		cout << it << ' ' << flush;
	}
	cout << endl << endl << endl;
	// calling clear() method
	my_list.clear();
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.push_back(3);
	my_list.push_back(4);
	my_list.push_back(4);
	for (LinkedList<int>::value_type it : my_list)
	{
		cout << it << ' ' << flush;
	}
}
