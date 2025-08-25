#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::ios_base::sync_with_stdio(false);

  string a, b;
  bool flag = false;
  cin >> a >> b;

  int na[10088] = {}, nb[10088] = {}, num[10088] = {};

  if (a.size() < b.size() || a.size() == b.size() && a < b) {
    swap(a, b);
    flag = true;
  }

  for (int i = 0; i < a.size(); ++i) {
    na[i] = a[a.size() - i - 1] - '0';
  }

  for (int i = 0; i < b.size(); ++i) {
    nb[i] = b[b.size() - i - 1] - '0';
  }

  int idx = 0;
  for (; idx < a.size(); ++idx) {
    num[idx] += na[idx] - nb[idx];
    if (num[idx] < 0) {
      num[idx + 1]--;
      num[idx] += 10;
    }
  }

  while (idx > 0 && num[idx] == 0) {
    idx--;
  }

  if (flag) {
    cout << '-';
  }

  while (idx >= 0) {
    cout << num[idx--];
  }

  return 0;
}
