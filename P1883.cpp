#include <bits/stdc++.h>
#include <climits>
#include <iomanip>
#include <ios>
#include <vector>

using namespace std;

struct fun {
  double a;
  double b;
  double c;
};

double sum(const vector<fun> &vec, double x) {

  double mmax = -INT_MAX;
  for (auto item : vec) {
    mmax = max(mmax, item.a * x * x + item.b * x + item.c);
  }

  return mmax;
}

void solve() {}

int main() {

  int T;
  cin >> T;

  while (T--) {

    long long n;
    cin >> n;

    vector<fun> vec(n);

    for (int i = 0; i < n; ++i) {
      cin >> vec[i].a >> vec[i].b >> vec[i].c;
    }

    double low = 0, heigh = 1000, delta;
    double Lb, Rb;

    while (heigh - low > 1e-5) {

      delta = (heigh - low) / 3;
      Lb = low + delta;
      Rb = heigh - delta;

      if (sum(vec, Lb) >= sum(vec, Rb)) {
        low = Lb;
      } else {
        heigh = Rb;
      }
    }

    cout << fixed << setprecision(4) << sum(vec, low) << endl;
  }

  return 0;
}
