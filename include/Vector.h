#ifndef VECTOR_H
#define VECTOR_H

#include <cstdint>

/**
 * This is a simple vector class.
 **/

template <typename T> class Vector {
public:
  // constructor
  Vector();

  // copy constructor
  Vector(const Vector &);

  // assignment op
  Vector<T> operator=(const Vector &);

  // destructor
  ~Vector();

  // Subscript op
  T operator[](uint32_t index);

  // Swap function
  void swap(Vector &);

  // get_size
  uint32_t get_size();

  // get_capacity
  uint32_t get_capacity();

  // insert
  void insert(uint32_t index, T item);

  // push_back
  void push_back(T item);

  // remove
  void remove(uint32_t index);

  // pop
  void pop();

  // append
  void append(const Vector &rhs);

private:
  uint32_t size;
  uint32_t capacity;
  T *arrPtr;
};

#endif
