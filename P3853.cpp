#include <bits/stdc++.h>
#include <vector>

using namespace std;

int L, N, K;
bool check(const vector<int> &vec, int num) {

  if (num == 0)
    return false;

  int cnt = 0;
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i] - vec[i - 1] > num)
      cnt += (vec[i] - vec[i - 1] - 1) / num;
  }

  return cnt <= K;
}

int main() {

  cin >> L >> N >> K;

  vector<int> vec(N + 1, 0);

  for (int i = 0; i < N; ++i) {
    cin >> vec[i];
  }

  int Lb = 0, Rb = 1e7 + 1;
  int mid;

  while (Rb - Lb > 0) {
    mid = Lb + (Rb - Lb) / 2;

    if (check(vec, mid)) {
      Rb = mid;
    } else {
      Lb = mid + 1;
    }
  }

  cout << Lb;

  return 0;
}
