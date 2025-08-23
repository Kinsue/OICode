#include <bits/stdc++.h>

using namespace std;

int main() {

  int a, b, c, d;

  cin >> a >> b >> c >> d;

  int m = 60 * (c - a) + d - b;

  cout << m / 60 << " " << m % 60 << endl;
  return 0;
}
