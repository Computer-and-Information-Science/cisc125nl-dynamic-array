#pragma once

#include <cstddef>

template <typename T>
class DynamicArray {
private:
  T* array;
  size_t capacity;
  size_t count;
  void expand_capacity(size_t new_capacity=0);
public:
  // Creates an empty array
  DynamicArray();

  // Recovers memory allocated by the array
  ~DynamicArray() { delete [] array; }

  // Removes the last element from the array, decreasing the size by 1
  void pop_back() { if (count > 0) count--; }

  // Adds one element to the end of the array, increasing the size by 1
  void push_back(const T& obj);

  // Changes the size of the array
  void resize(size_t new_size);

  // Returns the size of the array
  size_t size() const { return count; }

  // Provide direct access to array elements
  T& operator[](size_t index);
  T operator[](size_t index) const;
};

template <typename T>
DynamicArray<T>::DynamicArray() {
  // Set initial capacity to 10, and initial size to 0
  capacity = 10;
  array = new T[capacity];
  count = 0;
}

template <typename T>
void DynamicArray<T>::expand_capacity(size_t new_capacity) {
  // If new_capacity is not provided, set to 50% more than current capacity
  if (new_capacity == 0)
    new_capacity = capacity + capacity / 2;
  // If requested new_capacity is less than current capacity, do nothing
  if (new_capacity <= capacity)
    return;

  // Allocate a new array to temporary pointer p
  T* p = new T[new_capacity];

  // Copy all element from current array to new array
  for (int i = 0; i < capacity; i++)
    p[i] = array[i];

  // Recover memory used by current array
  delete [] array;

  // Set the new array as the current array (pointer assignment)
  array = p;

  // Update the capacity
  capacity = new_capacity;
}

template <typename T>
void DynamicArray<T>::push_back(const T& obj) {
  // Check for existing capacity to add another object
  if (capacity == count)
    expand_capacity();
  // Add object to end of array and update the count of objects
  array[count++] = obj;
}

template <typename T>
void DynamicArray<T>::resize(size_t new_size) {
  // Check for existing capacity to change size of the array
  if (new_size > capacity)
    expand_capacity(new_size);
  // Update the count of objects
  count = new_size;
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index) {
  // Check for a valid index, throw error if invalid
  if (index >= count)
    throw "Invalid array index";
  // Return the requested object
  return array[index];
}

template <typename T>
T DynamicArray<T>::operator[](size_t index) const {
  // Check for a valid index, throw error if invalid
  if (index >= count)
    throw "Invalid array index";
  // Return the requested object
  return array[index];
}
