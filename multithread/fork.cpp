#include <iostream>

using namespace std;

int main() {
  cout<<"starting"<<endl;
  pid_t pid = fork();
  if (pid == 0) {
    cout << "in child" << endl;
    exit(0);
  }
  else if (pid<0) {
    cerr << "failed to fork" << endl;
    exit(1);
  }
  else {
    cout << "in parent" << endl;
  }
  cout<<"abc"<<endl;
  return 1;
}
