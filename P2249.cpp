#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <vector>

using namespace std;

int check(const vector<int> &vec, int num) {

  int Lb = 0, Rb = vec.size();

  int mid;

  while (Rb - Lb) {
    mid = Lb + (Rb - Lb) / 2;
    if (vec[mid] < num) {
      Lb = mid + 1;
    } else {
      Rb = mid;
    }
  }

  if (vec[Lb] == num)
    return Rb + 1;

  return -1;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> vec(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  int num;
  int idx;
  while (m--) {
    cin >> num;

    idx = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
    if (vec[idx] == num)
      cout << idx + 1;
    else
      cout << -1;

    cout << " ";

    // cout << check(vec, num) << " ";
  }
  cout << endl;

  return 0;
}
