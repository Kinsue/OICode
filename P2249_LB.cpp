#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iterator>
#include <vector>
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  int query;

  cin >> n >> m;

  vector<int> vec(n);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> query;
    auto pos = lower_bound(vec.begin(), vec.end(), query);
    if (pos != vec.end() && *pos == query) {
      cout << (pos - vec.begin()) + 1 << " ";
    } else {
      cout << -1 << " ";
    }
  }

  return 0;
}
