#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;

ll check(const vector<ll> &vec, int num) {

  long long ans = 0;

  for (auto item : vec) {
    if (item > num) {
      ans += item - num;
    }
  }

  return ans;
}

int main() {

  ll N, M;
  cin >> N >> M;

  vector<ll> vec(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> vec[i];
  }

  int Lb = 0, Rb = 5e5;
  int mid;

  while (Rb - Lb > 0) {
    mid = Lb + (Rb - Lb) / 2;
    if (check(vec, mid) >= M) {
      Lb = mid + 1;
    } else {
      Rb = mid;
    }
  }

  cout << Lb - 1 << endl;

  return 0;
}
