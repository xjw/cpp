/**
 * generate all valid combination of parentheses
 *
 */

#include <iostream>
#include <string>
#include <vector>

#define N 3

using namespace std;

void getValidParentheses(string v, int left, int right) {

  if (left == N && right == N) {
    cout<<v<<endl;
  }

  if (left < N) {
    getValidParentheses(v+"(", left+1, right);
  }

  if (right < left && right < N) {
    getValidParentheses(v+")", left, right+1);
  }
}

int main() {
  getValidParentheses("", 0,0);
  return 1;
}
