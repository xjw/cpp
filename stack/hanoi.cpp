#include <iostream>
#include <stack>
#define N 5

using namespace std;

class Tower {
 public:
  Tower(int i);
  void add(int i);
  void move(int n, Tower *buffer, Tower *dest);
  void moveTopTo(Tower *dest);
  void print();
  int index();
 private:
  stack<int> disks;
  int idx;
};

Tower::Tower(int i) {
  idx = i;
}

int Tower::index() {
  return idx;
}

void Tower::print() {
  cout<<"tower "<<index()<<"-";
  while(!disks.empty()) {
    int top = disks.top();
    cout<<top;
    disks.pop();
  }
  cout<<endl;
}

void Tower::add(int i) {
  disks.push(i);
}

void Tower::move(int n, Tower *buffer, Tower *dest) {
  if (n>0) {
    move(n-1, dest, buffer);
    moveTopTo(dest);
    buffer->move(n-1, this, dest);
  }
}

void Tower::moveTopTo(Tower *dest) {
  int front = disks.top();
  disks.pop();
  dest->add(front);
  cout<<"moving front "<<front<< " from "<<index()<<" to "<<dest->index()<<endl;
}
  
int main() {
  Tower *towers[3];
  for (int i=0; i<3; ++i) {
    towers[i] = new Tower(i);
  }
  for (int i=N-1; i>=0; --i) {
    towers[0]->add(i);
  }

  towers[0]->move(N,towers[1], towers[2]);

  towers[0]->print();
  towers[1]->print();
  towers[2]->print();

  for (int i=0; i<3; ++i) {
    delete towers[i];
  }
}
