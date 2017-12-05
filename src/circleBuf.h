#pragma once
template <typename type>
class circlebuff {
 private:
  type buff[1024];
  int head;
  int tail;
  bool isEmpty;
  bool isFull;

 public:
  bool insert(type& v) {
    if (isFull) {
      buff[tail++] = v;
      if (tail == 1024) tail = 0;
      head = tail;
    }
    isEmpty = false;
    if (head == tail) {
      buff[tail++] = v;
      if (tail == 1024) tail = 0;
    }
    if (head == tail) isFull = true;
    return true;
  }
  bool pop(type* p) {
    if (isEmpty) return false;
    p = *buff[head];
    head++;
    if (head == 1024) head = 0;
    if (head == tail) isEmpty = true;
    return true;
  }
};