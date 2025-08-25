#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::ios_base::sync_with_stdio(false);

  string a, b;
  bool flag = false;
  cin >> a >> b;

  int na[10088] = {}, nb[10088] = {}, num[10088] = {};

  for (int i = 0; i < a.size(); ++i) {
    na[i] = a[a.size() - i - 1] - '0';
  }

  for (int i = 0; i < b.size(); ++i) {
    nb[i] = b[b.size() - i - 1] - '0';
  }

  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      num[i + j] += na[i] * nb[j];
      if (num[i + j] >= 10) {
        num[i + j + 1] += num[i + j] / 10;
        num[i + j] %= 10;
      }
    }
  }

  int idx = a.size() + b.size();
  while (idx > 0 && num[idx] == 0) {
    idx--;
  }

  while (idx >= 0) {
    cout << num[idx--];
  }

  return 0;
}
