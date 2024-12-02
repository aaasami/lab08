// testSimpleList1.cpp

#include <iostream>
#include <string>
#include "SimpleList.h"
#include "SimpleList.cpp"
#include "tddFuncs.h"

using namespace std;

int main() {

	cout << "Runing tests from: " << __FILE__ << endl;
	SimpleList<string> list;

	ASSERT_EQUALS(0, list.getNumElements());
	ASSERT_EQUALS(true, list.empty());

	list.insert("item1");
	list.insert("item2");
	list.insert("item3");

	ASSERT_EQUALS("item1", list.first());
	ASSERT_EQUALS("item3", list.last());
	ASSERT_EQUALS("item2", list.at(1));
	ASSERT_EQUALS(3, list.getNumElements());
	ASSERT_EQUALS(false, list.empty());

	list.remove(2);
	ASSERT_EQUALS("item1", list.first());
	ASSERT_EQUALS("item2", list.last());
	ASSERT_EQUALS(2, list.getNumElements());
	ASSERT_EQUALS(false, list.empty());

	list.remove(0);
	ASSERT_EQUALS("item2", list.at(0));

	list.remove(0);
	ASSERT_EQUALS(0, list.getNumElements());
	ASSERT_EQUALS(true, list.empty());

	return 0;
}