#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "../include/Vector.h"
#include <algorithm>

template <typename T>
Vector<T>::Vector() : size(0), capacity(100), arrPtr(new T[100]){};

template <typename T> Vector<T>::Vector(const Vector &rhs) {
  T *tmpPtr = new T[rhs.capacity];
  for (uint32_t i = 0; i < rhs.size; i++) {
    tmpPtr[i] = rhs.arrPtr[i];
  }
  std::swap(tmpPtr, arrPtr);
  size = rhs.size;
  capacity = rhs.capacity;
}

template <typename T> 
Vector<T> Vector<T>::operator=(const Vector &rhs) {
	Vector<T> tmpVec(rhs);
	tmpVec.swap(*this);
}

template <typename T>
Vector<T>::~Vector() {
	delete[] arrPtr;
	arrPtr = nullptr;
}

template <typename T>
T Vector<T>::operator[](uint32_t index) {
	return arrPtr[index];
}

template <typename T>
void Vector<T>::swap(Vector &rhs) {
	std::swap(arrPtr, rhs.arrPtr);
	std::swap(size, rhs.size);
	std::swap(capacity, rhs.capacity);
}

template <typename T>
uint32_t Vector<T>::get_size() {
	return size;
}

template <typename T>
uint32_t Vector<T>::get_capacity() {
	return capacity;
}

template <typename T>
void Vector<T>::push_back(T item) {
	if(size == capacity) {
		T *tmpPtr = new T[capacity*2];
		for(uint32_t i = 0; i < size; i++) {
			tmpPtr[i] = arrPtr[i];
		}
		tmpPtr[size] = item;
		std::swap(arrPtr, tmpPtr);
		capacity *= 2;
	}
	else {
		T *tmpPtr = new T[capacity];
		for (uint32_t i = 0; i < size; i++) {
			tmpPtr[i] = arrPtr[i];
		}
		tmpPtr[size] = item;
		std::swap(arrPtr, tmpPtr);
	}
	size += 1;
}

template <typename T>
void Vector<T>::insert(uint32_t index, T item) {
	if (index == size) {
		push_back(item);
	}
	else if (index > size) {
		while(index <= size) {
			push_back(item);
		}
	}
	else { 
		if (size == capacity) {
			T* tmpPtr = new T[capacity*2];
			for(uint32_t i = 0; i < index; i++) {
				tmpPtr[i] = arrPtr[i];
			}
			tmpPtr[index] == item;
			for(uint32_t i = index+1; i <= size; i++) {
				tmpPtr[i] = arrPtr[i-1];
			}
			std::swap(tmpPtr, arrPtr);
			capacity *= 2;
		}
		else {
			T* tmpPtr = new T[capacity];
			for(uint32_t i = 0; i < index; i++) {
				tmpPtr[i] = arrPtr[i];
			}
			tmpPtr[index] == item;
			for(uint32_t i  = index+1; i <= size; i++) {
				tmpPtr[i] = arrPtr[i-1];
			}
			std::swap(tmpPtr, arrPtr);
		}
		size += 1;
	}
}

template <typename T>
void Vector<T>::pop() {
	size -= 1;
}

template <typename T>
void Vector<T>::remove(uint32_t index) {
	if (index == size-1) {
		size -= 1;
	}
	T* tmpPtr = new T[capacity];
	for(uint32_t i = 0; i < index; i++) {
		tmpPtr[i] = arrPtr[i];
	}
	for(uint32_t i = index; i < size-1; i++) {
		tmpPtr[i] == arrPtr[i+1];
	}
	std::swap(tmpPtr, arrPtr);
	size -= 1;
}	

template <typename T>
void Vector<T>::append(const Vector &rhs) {
	T* tmpPtr = new T[capacity+rhs.capacity];
	for(uint32_t i = 0; i < size; i++) {
		tmpPtr[i] = arrPtr[i];
	}
	for(uint32_t i = size; i < size+rhs.size; i++) {
		tmpPtr[i+size] = rhs.arrPtr[i];
	}
	std::swap(tmpPtr, arrPtr);
	size += rhs.size;
	capacity += rhs.capacity;
}
#endif
