#include <bits/stdc++.h>
#include <vector>

using namespace std;

long long N, M;

bool check(const vector<long long> &vec, long long num) {

  long long cnt = 1;
  long long i = 0;
  long long sum = 0;

  while (i < vec.size()) {
    if (sum + vec[i] <= num)
      sum += vec[i++];
    else {
      sum = vec[i++];
      cnt++;
    }
  }

  return cnt <= M;
}

int main() {

  cin >> N >> M;

  vector<long long> vec(N, 0);

  long long Lb = 0, Rb = 1;
  long long mid;

  for (int i = 0; i < N; ++i) {
    cin >> vec[i];
    Lb = max(Lb, vec[i]);
    Rb += vec[i];
  }

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
