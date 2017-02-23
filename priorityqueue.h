#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename T>
class PriorityQueue {
  friend class CanvasView;
  friend class MainWindow;

 public:
  PriorityQueue();

  ~PriorityQueue();

  void add(T item);

  void pop();

  T top();

  inline int getSize() { return lastAddedItem; }

 protected:
  T at(int pos) { return items[pos]; }

  T* items;
  int lastAddedItem;
  int buffSize;
};

#endif  // PRIORITYQUEUE_H
