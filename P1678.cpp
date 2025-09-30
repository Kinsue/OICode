#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int lower(const vector<int> &vec, int num) {

  int Lb = 0, Rb = vec.size();
  int mid;

  while (Rb - Lb > 0) {
    mid = Lb + (Rb - Lb) / 2;
    if (vec[mid] < num) {
      Lb = mid + 1;
    } else {
      Rb = mid;
    }
  }

  return Lb;
}

int upper(const vector<int> &vec, int num) {

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
  return Lb;
}

int main() {

  int m, n;
  cin >> m >> n;

  vector<int> sch(m), stu(n);

  for (int i = 0; i < m; ++i)
    cin >> sch[i];

  for (int i = 0; i < n; ++i)
    cin >> stu[i];

  sort(sch.begin(), sch.end());

  long long ans = 0;
  int lowb, upb;

  for (int i = 0; i < n; ++i) {

    // lowb = lower_bound(sch.begin(), sch.end(), stu[i]) - sch.begin();
    // upb = upper_bound(sch.begin(), sch.end(), stu[i]) - sch.begin();
    //
    lowb = lower(sch, stu[i]);
    upb = upper(sch, stu[i]);

    if (sch[lowb] != stu[i] && lowb != 0)
      lowb--;

    ans += min(abs(sch[lowb] - stu[i]), abs(sch[upb] - stu[i]));
  }

  cout << ans;

  return 0;
}
