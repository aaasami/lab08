// testSimpleList3.cpp

#include <iostream>
#include <string>
#include "SimpleList.h"
#include "SimpleList.cpp"
#include "tddFuncs.h"

using namespace std;

void testDestructor1() {
	SimpleList<string*> list2;
	string* s1 = new string("something1");
	string* s2 = new string("something2");
	list2.insert(s1);
	list2.insert(s2);
}

void testDestructor2() {
	SimpleList<string*>* list3 = new SimpleList<string*>();
	string* s1 = new string("something1");
	string* s2 = new string("something2");
	list3->insert(s1);
	list3->insert(s2);
	delete list3;
}

int main() {

	cout << "Runing tests from: " << __FILE__ << endl;
	
	SimpleList<string*> list;
	string* s1 = new string("item1");
	string* s2 = new string("item2");

	list.insert(s1);
	list.insert(s2);

	ASSERT_EQUALS("item1", *list.at(0));
	ASSERT_EQUALS("item1", *list.first());
	ASSERT_EQUALS("item2", *list.last());
	ASSERT_EQUALS(2, list.getNumElements());

	list.remove(0);
	list.remove(0);

	testDestructor1();
	testDestructor2();

	return 0;
}