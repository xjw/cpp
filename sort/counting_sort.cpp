#include <iostream>
#include <map>

using namespace std;

void counting_sort(int *a, int n) {
  if (n<1) return;

  int max, min;
  max = min = a[0];
  for(int i=0; i<n; ++i) {
    if (a[i]>max) max = a[i];
    if (a[i]<min) min = a[i];
  }

  int count_size = max-min+1;

  int *count_array = new int[count_size];
  for (int i=0; i<count_size; ++i) {
    count_array[i] = 0;
  }

  for(int i=0; i<n; ++i) {
    count_array[a[i]-min]++;
  }

  for(int i=0, j=0; i<count_size; ++i) {
    int count = count_array[i];
    while(count--) {
      a[j++] = i+min;
      // cout<<i+min<<endl;
    }
  }

  delete count_array;
}

void counting_sort_using_map(int *a, int n) {
  map<int, int> m;

  for(int i=0; i<n; ++i) {
    m[a[i]]++;
  }

  for(map<int,int>::iterator it=m.begin(); it!=m.end(); ++it) {
    int count = (*it).second;
    while(count--) {
      cout << (*it).first << endl;
    }
  }
}

int main() {
  int a[] = {1,2,3,4,5,1,2,3,4,5};
  int size = sizeof(a)/sizeof(a[0]);
  counting_sort(a, size);
  for (int i=0; i<size; ++i) {
    cout<<a[i]<<endl;
  }
  return 1;
}
