#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> D(n + 1, 0);

  int p, pn;

  cin >> p;
  for (int i = 1; i < m; ++i) {
    cin >> pn;
    D[min(p, pn)] += 1;
    D[max(p, pn)] -= 1;
    p = pn;
  }

  for (int i = 1; i < n; ++i)
    D[i] += D[i - 1];

  long long a, b, c;
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    cin >> a >> b >> c;
    ans += min(D[i] * a, D[i] * b + c);
  }

  cout << ans << endl;

  return 0;
}
