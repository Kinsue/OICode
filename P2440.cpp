#include <bits/stdc++.h>
using namespace std;

long long n, k;

bool check(const vector<long long> &vec, int num) {

  if (num == 0)
    return false;

  long long ans = 0;

  for (auto item : vec) {
    ans += item / num;
  }

  return ans >= k;
}

int main() {

  cin >> n >> k;

  vector<long long> vec(n, 0);
  for (int i = 0; i < n; ++i)
    cin >> vec[i];

  long long Lb = 0, Rb = 1e8 + 1;
  long long mid;

  while (Rb - Lb > 0) {
    mid = Lb + (Rb - Lb) / 2;

    if (check(vec, mid)) {
      Lb = mid + 1;
    } else {
      Rb = mid;
    }
  }

  if (Lb)
    cout << Lb - 1;
  else
    cout << 0;

  return 0;
}
