#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, r;
  cin >> n >> r;

  vector<int> vec(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    cin >> vec[i];
  }

  int Lb = 1, Rb = n;
  while (vec[Lb] && Lb <= r)
    Lb++;
  while (vec[Rb] && Rb > r)
    Rb--;

  int ans = Rb - Lb + 1;
  for (int i = Lb; i <= Rb; ++i) {
    ans += vec[i];
  }

  cout << ans << endl;

  return 0;
}
