// testSimpleList2.cpp

#include <iostream>
#include <string>
#include "SimpleList.h"
#include "SimpleList.cpp"
#include "tddFuncs.h"

using namespace std;

int main() {

	cout << "Runing tests from: " << __FILE__ << endl;
	SimpleList<int> list;
	bool caughtEmptyListException = false;
	bool caughtFullListException = false;
	bool caughtInvalidIndexException = false;

	try {
		list.remove(0);
	} catch (EmptyListException e) {
		caughtEmptyListException = true;
	}
	ASSERT_EQUALS(true, caughtEmptyListException);
	caughtEmptyListException = false;

	try {
		list.first();
	} catch (EmptyListException e) {
		caughtEmptyListException = true;
	}
	ASSERT_EQUALS(true, caughtEmptyListException);
	caughtEmptyListException = false;

	try {
		list.last();
	} catch (EmptyListException e) {
		caughtEmptyListException = true;
	}
	ASSERT_EQUALS(true, caughtEmptyListException);
	caughtEmptyListException = false;

	list.insert(0);
	try {
		list.at(0);
	} catch (InvalidIndexException e) {
		caughtInvalidIndexException = true;
	}
	ASSERT_EQUALS(false, caughtInvalidIndexException);
	caughtInvalidIndexException = false;

	try {
		list.at(1);
	} catch (InvalidIndexException e) {
		caughtInvalidIndexException = true;
	}
	ASSERT_EQUALS(true, caughtInvalidIndexException);
	caughtInvalidIndexException = false;

	try {
		list.at(-1);
	} catch (InvalidIndexException e) {
		caughtInvalidIndexException = true;
	}
	ASSERT_EQUALS(true, caughtInvalidIndexException);
	caughtInvalidIndexException = false;

	for (int i = 1; i < list.CAPACITY; i++) {
		list.insert(i);
	}

	ASSERT_EQUALS(0, list.first());
	ASSERT_EQUALS(9, list.last());
	ASSERT_EQUALS(10, list.getNumElements());

	try {
		list.insert(100);
	} catch (FullListException e) {
		caughtFullListException = true;
	}
	ASSERT_EQUALS(true, caughtFullListException);
	caughtFullListException = false;

	try {
		list.at(10);
	} catch (InvalidIndexException e) {
		caughtInvalidIndexException = true;
	}
	ASSERT_EQUALS(true, caughtInvalidIndexException);
	caughtInvalidIndexException = false;

	return 0;
}