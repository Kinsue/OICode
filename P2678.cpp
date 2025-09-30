#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int L, N, M;
bool check(vector<int> &vec, int dis) {

  int i = 0, j = 1;
  int cnt = M;

  while (j < vec.size()) {
    while (vec[j] - vec[i] >= dis)
      i = j, j++;

    while (vec[j] - vec[i] < dis && j < vec.size()) {
      cnt--;
      j++;
    }
  }

  return cnt >= 0;
}

int main() {

  cin >> L >> N >> M;

  vector<int> vec(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    cin >> vec[i];
  }
  vec.push_back(L);

  int Lb = 1, Rb = L + 1;
  int mid;

  while (Rb - Lb >= 1) {
    mid = Lb + (Rb - Lb) / 2;

    if (check(vec, mid)) {
      Lb = mid + 1;
    } else {
      Rb = mid;
    }
  }

  cout << Lb - 1;

  return 0;
}
