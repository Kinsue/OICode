#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int l, m;
  cin >> l >> m;

  if (m == 0) {
    cout << l + 1 << endl;
    return 0;
  }

  vector<pair<int, int>> range(m);
  for (int i = 0; i < m; ++i) {
    cin >> range[i].first >> range[i].second;
  }

  sort(range.begin(), range.end());

  int mergeidx = 0;

  for (int i = 0; i < m; ++i) {
    if (mergeidx == 0 || range[i].first > range[mergeidx - 1].second) {
      range[mergeidx++] = range[i];
    } else {
      range[mergeidx - 1].second =
          max(range[mergeidx - 1].second, range[i].second);
    }
  }

  int result = l + 1;
  for (int i = 0; i < mergeidx; ++i) {
    result -= range[i].second - range[i].first + 1;
  }
  cout << result;
  return 0;
}
