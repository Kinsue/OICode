#include <bits/stdc++.h>
using namespace std;

long long n, m, s;
vector<int> w, v, L, R;

long long check(int W) {

  static long long cnt[200005], sumv[200005];
  cnt[0] = sumv[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (w[i] >= W) {
      cnt[i] = cnt[i - 1] + 1;
      sumv[i] = sumv[i - 1] + v[i];
    } else {
      cnt[i] = cnt[i - 1];
      sumv[i] = sumv[i - 1];
    }
  }

  long long res = 0;
  for (int i = 0; i < m; i++) {
    long long num = cnt[R[i]] - cnt[L[i] - 1];
    long long val = sumv[R[i]] - sumv[L[i] - 1];
    res += num * val;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> s;

  w.resize(n + 1);
  v.resize(n + 1);
  L.resize(m);
  R.resize(m);

  for (int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  for (int i = 0; i < m; i++)
    cin >> L[i] >> R[i];

  int Lb = 1, Rb = 1000000 + 1;
  long long ans = LLONG_MAX;

  while (Rb - Lb >= 0) {
    int mid = Lb + (Rb - Lb) / 2;
    long long val = check(mid);
    ans = min(ans, llabs(s - val));
    if (val >= s) {
      Lb = mid + 1;
    } else {
      Rb = mid - 1;
    }
  }

  cout << ans << "\n";
  return 0;
}
