#include <iostream>
using namespace std;

int main() {

  int n, m;
  int a[10004] = {};
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  /*
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    sum += a[i];
  }

  int mmin = sum;
  for (int i = m; i < n; ++i) {
    sum -= a[i - m];
    sum += a[i];
    mmin = min(sum, mmin);
  }
  */

  for (int i = 1; i < n; ++i) {
    a[i] += a[i - 1];
  }

  int mmin = a[m - 1];

  for (int i = m; i < n; ++i) {
    mmin = min(mmin, a[i] - a[i - m]);
  }

  cout << mmin;

  return 0;
}
