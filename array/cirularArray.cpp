/**
 * http://en.wikipedia.org/wiki/Circular_buffer
 * http://www.google.com/url?sa=t&source=web&cd=4&ved=0CCkQFjAD&url=http%3A%2F%2Fwww.cs.sfu.ca%2FCC%2F225%2Fjmanuch%2Flec%2F5-1.ppt&ei=4QbSTJPZE4aisAP0vNC0Cw&usg=AFQjCNFhghd09WijPgg-SmC2Sa2yNy5KXA&sig2=knAoJZdpGXidc1Ka1qKbqg
 *  
 */

#include <iostream>

using namespace std;

const int SIZE=10;

class CircularArray {
 public:
  bool empty();
  void push(int x);
  int pop();
  int front();
  int back();
  int size();
  CircularArray();
  ~CircularArray();
 private:
  int front;
  int count;
  int *data;
};

CircularArray::CircularArray() {
  data = new int[SIZE];
  count = 0;
  front = -1;
}

CircularArray::~CircularArray() {
  delete [] data;
}

int CircularArray::size() {
  return count;
}

int main() {
  return 1;
}
