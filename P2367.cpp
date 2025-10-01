#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int main() {

  int n, p;
  cin >> n >> p;

  vector<int> vec(n + 1, 0);
  vector<int> dec(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    cin >> vec[i];
    dec[i] = vec[i] - vec[i - 1];
  }

  int x, y, z;
  while (p--) {
    cin >> x >> y >> z;
    dec[x] += z;
    dec[y + 1] -= z;
  }

  int mmin = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    vec[i] = vec[i - 1] + dec[i];
    mmin = min(mmin, vec[i]);
  }

  cout << mmin << endl;

  return 0;
}
