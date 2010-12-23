#include <iostream>
#include <map>
#include <vector>

using namespace std;

const double precision=0.01;

class Point {
 public:
  double x;
  double y;
};

class Line {
 public:
  double slope;
  bool straight;
  Line(Point, Point);
  bool operator <(const Line& rhs) const;
};

Line::Line(Point p1, Point p2) {
  straight = (p2.x == p1.x)? true : false;
  slope = straight? p2.x : (p2.y-p1.y)/(p2.x-p1.x);
}

/**
 * http://stackoverflow.com/questions/1102392/stl-maps-with-user-defined-objects
 *
 * define operator< for your custom class.
 *
 * Just ensure that it obeys the strictly weakly comparable requirements, which are: 
 * (a) (x < x) == false
 * (b) if x < y, than !(y < x)
 * (c) if x < y and y < z than x < z
 * (d) Equivalence: If x and y are equivalent, than (x < y) == false and (y < x) == false 
 */

bool Line::operator <(const Line&rhs) const {
  if (straight ^ rhs.straight) return false;
  return rhs.slope-slope>precision;
}

Line findLineWithMostPoints(vector<Point> v) {
  map<Line, int>m;
  for (vector<Point>::iterator it1=v.begin(); it1!=v.end(); ++it1) {
    for (vector<Point>::iterator it2=v.begin(); it2!=v.end(); ++it2) {
      if (it1 != it2) {
        Line l = Line(*it1, *it2);
        if (m.end() != m.find(l)) {
          m[l]++;
        }
      }
    }
  }
  map<Line, int>::iterator it, max;
  it = max = m.begin();
  for(; it!=m.end(); ++it) {
    if (it->second > max->second) {
      max = it;
    }
  }
  return max->first;
}

int main() {
  return 1;
}
