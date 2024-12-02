//SHUANG LI
//PERM: A2K6Y57
//SimpleList.cpp to be completed by the student
#include "SimpleList.h"
#include <iostream>
#include <cstring>
#include <type_traits>

template <class T>
SimpleList<T>::SimpleList():numElements(0){
    elements = new T[CAPACITY];
}

template <class T>
SimpleList<T>::~SimpleList(){
    if constexpr(std::is_pointer<T>::value){
        for(int i = 0; i < numElements; ++i){
            delete elements[i];
        }
    }
    delete[] elements;
}

template <class T>
T SimpleList<T>::at(int index) const {
    if (index < 0 || index >= numElements) {
        throw InvalidIndexException();
    }
    return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const {
    return numElements == 0;
}

template <class T>
T SimpleList<T>::first() const {
    if (empty()) {
        throw EmptyListException();
    }
    return elements[0];
}

template <class T>
T SimpleList<T>::last() const {
    if (empty()) {
        throw EmptyListException();
    }
    int temp = numElements - 1;
    return elements[temp];
}

template <class T>
int SimpleList<T>::getNumElements() const {
    return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) {
    if (numElements >= CAPACITY) {
        throw FullListException();
    }
    elements[numElements++] = item;
}

template <class T>
void SimpleList<T>::remove(int index) {
    if (empty()) {
        throw EmptyListException();
    }
    if (index < 0 || index >= numElements) {
        throw InvalidIndexException();
    }
    if constexpr (std::is_pointer<T>::value) {

        delete elements[index];
    }
    for (int i = numElements - 1; i > index; --i) {
        elements[i - 1] = elements[i];
    }
    --numElements;
}
