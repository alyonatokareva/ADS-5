// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

template<typename t, int size>
class tStack {
private:
     t arr[size];
     int top;
 public:
     tStack() : top(-1) {}
     bool empty() const {
         return top == -1;
     }
     bool full() const {
         return top == size - 1;
     }
     t get() {
         if (isEmpty()) {

         } else {
             return arr[top];
         }
     }
     void top() {
         if (top >= 0)
             top--;
     }
     void push(t value) {
         if (top < size - 1)
             arr[++top] = value;
     }
}
