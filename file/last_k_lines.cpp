#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print_last_k_lines(char *file_name, int k) {
  string *a = new string[k];
  ifstream file;
  file.open(file_name);
  int count = 0;
  int start = 0;

  if (file.is_open()) 
  {
    string temp;
    while(getline(file, temp)) {
      a[count++%k] = temp;
      // count++;
    }
  }

  if (count>k) {
    start = count % k;
    count = k;
  }
  else {
    start = 0;
  }

  for (int i=0; i<count; ++i) {
    cout<<a[(i+start)%k]<<endl;
  }

  delete[] a;
}

int main() {
  print_last_k_lines("test.txt", 30);
  return 1;
}
