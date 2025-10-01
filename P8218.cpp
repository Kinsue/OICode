#include <bits/stdc++.h>
#include <sys/types.h>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n;

  vector<int> vec(n + 1, 0);
  vector<int> pre(n + 1, 0);

  for (int i = 1; i <= n; ++i)
    cin >> vec[i];

  for (int i = 1; i <= n; ++i)
    pre[i] = vec[i] + pre[i - 1];

  cin >> m;
  int L, R;
  while (m--) {
    cin >> L >> R;
    cout << pre[R] - pre[L - 1] << endl;
  }

  return 0;
}
