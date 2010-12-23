#include <iostream>
#include <algorithm>

using namespace std;

int findPosition(int arr[], int size) {
  int numofZero = 0;
  int numofOne = 0;

  for (int i=0; i<size; ++i) {
    if (arr[i] == 0) {
      ++numofZero;
    }
    else if (arr[i] == 1) {
      ++numofOne;
    }
  }

  int l0, l1, r0, r1, pos, curMin, minError;

  l0 = l1 = pos = 0;
  r0 = numofZero - l0;
  r1 = numofOne - l1;

  minError = size*10;

  for (int i=0; i<size; ++i) {
    if (arr[i] == 1) {
      ++l1;
      --r1;
    }
    else if (arr[i] == 0) {
      ++l0;
      --r0;
    }

    curMin = min(l1+r0, l0+r1);
    minError = min(minError, curMin);

    if (minError == curMin) {
      pos = i;
    };
  }

  cout<<"pos-"<<pos<<endl;
  cout<<"min-"<<minError<<endl;

  return 0;
}

int main() {
  int arr[] = {0,0,0,1,1,0,1,1};
  findPosition(arr, sizeof(arr)/sizeof(int));
  return 0;
}
