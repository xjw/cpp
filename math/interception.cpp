/**
 *  P189 CUP
 *  OBSERVATIONS AND SUGGESTIONS:
 *
 *  »»Ask questions. This question has a lot of unknowns—ask questions to clarify them. 
 *  Many interviewers intentionally ask vague questions to see if you’ll clarify your assumptions.
 *
 *  »»When possible, design and use data structures. It shows that you understand and care about object oriented design.
 *
 *  »»Think through which data structures you design to represent a line. There are a lot of options, with lots of trade offs. Pick one and explain your choice.
 *
 *  »»Don’t assume that the slope and y-intercept are integers.
 *
 *  »»Understand limitations of floating point representations. Never check for equality with ==.
 */

#include <iostream>
#include <stdlib.h>

#define PRECISION 0.0001

using namespace std;

class line {
 public:
  line(double s, double y) {slope=s;yintercept=y;}
  double slope;
  double yintercept;
};

bool intercept(line a, line b) {
  return (abs(a.slope - b.slope) > PRECISION) || (abs(a.yintercept - b. yintercept) < PRECISION);
}

int main() {
  return 1;
}
