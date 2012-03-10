#include <iostream>
#include <limits.h>

using namespace std;

int beat_stock_market(int p[], int n) {
  if (n<2) return 0;

  int buy_date, sell_date, lowest_date, lowest, best_deal;
  lowest = p[0];
  buy_date = lowest_date = 0;
  best_deal = INT_MIN;

  for (int i=1; i<n; ++i) {
    if (p[i]-lowest>best_deal) {
      best_deal = p[i]-lowest;
      buy_date = lowest_date;
      sell_date = i;
    }
    if (p[i]<lowest) {
      lowest=p[i];
      lowest_date = i;
    }
  }

  cout<< "Best deal is buy at day " << buy_date+1 << " with price " << p[buy_date];
  cout<< " and sell on day " << sell_date+1 << " with price " << p[sell_date];
  cout<< ". Profit: " << best_deal << endl;

  return best_deal;
}

int simple(int p[], int n) {
  int buy, sell, min, maxDiff;
  buy = sell = min = maxDiff = 0;
  for (int i=0; i<n; ++i) {
    if (p[i]<p[min]) min = i;
    int diff = p[i] - p[min];
    if (diff > maxDiff) {
      maxDiff = diff;
      buy = min;
      sell = i;
    }
  }
}


int main() {
  // int price[] = {2,3,5,4,1,3,2,3};
  int price[] = {4,3,2,1};
  beat_stock_market(price, sizeof(price)/sizeof(price[0]));
  return 1;
}
