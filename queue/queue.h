template <class T>
class Queue {
 public:
  Queue(int n);
  ~Queue();
  void push(T data);
  T front();
  void pop();
  bool empty();
 private:
  T *elements;
  int idx;
};

template <class T>
Queue<T>::Queue(int n) {
  elements = new T[n];
  idx = -1;
}

template <class T>
Queue<T>::~Queue() {
  delete[] elements;
  elements = NULL;
  idx = -1;
}

template <class T>
void Queue<T>::push(T data) {
  elements[++idx] = data;
}

template <class T>
bool Queue<T>::empty() {
  return idx<0;
}

template <class T>
void Queue<T>::pop() {
  if (!empty()) {
    idx--;
  }
}
