#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;

int main() {

  string a, b;
  int na[505] = {}, nb[505] = {};
  int num[600] = {};

  cin >> a >> b;
  int len = max(a.size(), b.size());

  // reverse(a.begin(), a.end());
  // reverse(b.begin(), b.end());

  for (int i = 0; i < a.size(); ++i) {
    na[i] = a[a.size() - i - 1] - '0';
  }

  for (int i = 0; i < b.size(); ++i) {
    nb[i] = b[b.size() - i - 1] - '0';
  }

  int idx = 0;
  for (; idx <= max(a.size(), b.size()); ++idx) {
    num[idx] += na[idx] + nb[idx];
    if (num[idx] >= 10) {
      num[idx + 1] = num[idx] / 10;
      num[idx] %= 10;
    }
  }

  while (idx > 0 && num[idx] == 0) {
    idx--;
  }

  while (idx >= 0) {
    cout << num[idx--];
  }

  return 0;
}
