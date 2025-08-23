#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

struct point {
  double x;
  double y;
} a, b, c;

double len(point a, point b) {

  double ans = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

  return ans;
}

int main() {

  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cin >> c.x >> c.y;

  double P = len(a, b) + len(a, c) + len(b, c);

  cout << fixed << setprecision(2) << P;

  return 0;
}
