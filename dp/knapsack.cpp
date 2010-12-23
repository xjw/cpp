#include <iostream>

using namespace std;

int v[] = {1, 2, 4};
int w[] = {2, 3, 5};
int W = 6;
int N = 3;

int k_1(int cap) {
  if (cap <= 0) return 0;
  int max = 0;
  for (int i=0, t=0; i<N; ++i) {
    if (w[i]<=cap && (t = v[i]+k_(cap-w[i]))>max) max = t;
  }
  return max;
}

int k_2(int cap) {
  static int calculated[100];
  if (calculated[cap]) return calculated[cap];
  int max=0;
  for (int i=0, t=0; i<N; ++i) {
    if (w[i]<=cap && ((t=v[i]+k01_2(cap-w[i]))>max)){
      max=t;
    }
  }
  // cout<<cap<<"-"<<max<<endl;
  return calculated[cap] = max;
}

int k(int i, int W) {
  if (i==0 || w==0) return 0;
  return max(k(i-1,W), k(i-1, W-w[i])+v[i]);
}

int main() {
  cout<< k(W) <<endl;
  cout<< k01_1(W) <<endl;
  cout<< k01_2(W) <<endl;
  return 1;
}
