#include <iostream>
#include <stdlib.h>
#include <map>

#define PRECISION 0.001

using namespace std;

class Point{
  public:
    double x;
    double y;
    Point(double a, double b) {x=a;y=b;}
};

class Line{
  public:
    double slope;
    double intercept;
    bool infiniteSlope;
    Line(Point a, Point b);
    bool operator<(Line l2) const;
};

Line::Line(Point a, Point b) {
  infiniteSlope = (abs(a.x - b.x) < PRECISION)? true : false;

  if (!infiniteSlope) {
    slope = (a.y - b.y)/(a.x - b.x);
    intercept = a.y - slope * a.x;
  }
  else {
    intercept = a.x;
  }
}

bool Line::operator<(Line l2) const {
  return (slope != l2.slope) || (intercept != l2.intercept);
}

int main() {
  Point points[] = {
    Point(1.0,1.0),
    Point(2.0,2.0),
    Point(3.0,3.0),
    Point(4.0,9.0)
  };
  int size = sizeof(points)/sizeof(points[0]);

  map<Line, int> m;
  for (int i=0; i<size; ++i) {
    for (int j=i+1; j<size; ++j) {
      Line a(points[i],points[j]);
      m[a]++;
    }
  }

  for (map<Line, int>::iterator it=m.begin(); it!=m.end(); ++it) {
    cout<<(*it).first.slope<<endl;
    cout<<(*it).second<<endl;
  }
  // for(int i=0; i<sizeof(points)/sizeof(points[0])
  // Line a(p1,p2);
  // Line b(p2,p3);
  // Line c(p3,p4);
  // cout<<a.slope<<"-"<<a.intercept<<endl;
  // cout<<b.slope<<"-"<<b.intercept<<endl;
  // cout<<c.slope<<"-"<<c.intercept<<endl;
  // map<Line, int> m;
  // m[a] = 1;
  // m[b] = 2;
  // m[c] = 3;
  // cout<<m.find(b)->second<<endl;
  // cout<<m.find(c)->second<<endl;
  return 1;
}
