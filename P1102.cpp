#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n, c;

int lob(vector<int> &vec, int num) {

  int Lb = 0, Rb = vec.size();
  int mid;

  while (Rb - Lb > 0) {
    mid = Lb + (Rb - Lb) / 2;
    if (vec[mid] >= num) {
      Rb = mid;
    } else {
      Lb = mid + 1;
    }
  }

  return Lb - 1;
}

int uob(vector<int> &vec, int num) {

  int Lb = 0, Rb = vec.size();
  int mid;

  while (Rb - Lb > 0) {
    mid = Lb + (Rb - Lb) / 2;
    if (vec[mid] > num) {
      Rb = mid;
    } else {
      Lb = mid + 1;
    }
  }

  return Lb - 1;
}

int main() {

  cin >> n >> c;
  vector<int> vec(n);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end());

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    /*
    ans += (upper_bound(vec.begin(), vec.end(), vec[i] + c) -
            lower_bound(vec.begin(), vec.end(), vec[i] + c));
            */
    ans += uob(vec, vec[i] + c) - lob(vec, vec[i] + c);
    // ans += solve(vec, vec[i] + c);
  }

  cout << ans;

  return 0;
}
