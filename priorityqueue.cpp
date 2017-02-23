#include "priorityqueue.h"

template <typename T>
PriorityQueue<T>::PriorityQueue() {
  buffSize = 100;
  items = new T[buffSize];
  lastAddedItem = 0;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
  delete[] items;
}

template <typename T>
void PriorityQueue<T>::add(T item) {
  if (buffSize == lastAddedItem) {
    buffSize *= 10;
    T* newItemArra = new T[lastAddedItem];
    for (int i = 0; i < lastAddedItem; i++)
      newItemArra[i] = items[i];
    delete items;
    items = newItemArra;
  }
  items[lastAddedItem] = item;
  lastAddedItem++;
  int swapPos = lastAddedItem;
  T tempValue;
  while (swapPos > 0 && items[swapPos - 1] < items[swapPos / 2 - 1]) {
    tempValue = items[swapPos - 1];
    items[swapPos - 1] = items[swapPos / 2 - 1];
    items[swapPos / 2 - 1] = tempValue;
    swapPos /= 2;
  }
}

template <typename T>
void PriorityQueue<T>::pop() {}

template <typename T>
T PriorityQueue<T>::top() {
  return items[0];
}

template class PriorityQueue<int>;
