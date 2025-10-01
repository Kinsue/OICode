#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<string> vec(n);
  vector<string> tgt;
  string T;

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  cin >> T;

  for (auto item : vec) {
    if (item.size() < T.size() || T != item.substr(0, T.size())) {
      continue;
    }
    tgt.push_back(item);
  }

  sort(tgt.begin(), tgt.end());

  for (auto item : tgt) {
    cout << item << endl;
  }

  return 0;
}
