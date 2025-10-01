#include <bits/stdc++.h>
// #include <climits>

using namespace std;

struct city {
  int num;
  int dis;
  string name;
} cs[55];

void force() {

  int n = 0;

  do {
    cin >> cs[n].num >> cs[n].dis >> cs[n].name;
  } while (cs[n++].name == "Moscow");
  // cout << n << endl;

  int mmin = INT_MAX;
  int distance, ansidx;

  for (int stop = 0; stop < n; ++stop) {
    distance = 0;
    for (int start = 0; start < n; ++start) {
      distance += abs(cs[start].dis - cs[stop].dis) * cs[start].num;
    }

    if (distance < mmin) {
      mmin = distance;
      ansidx = stop;
    }
  }

  cout << cs[ansidx].name << " " << mmin << endl;
}

int main() {

  force();

  return 0;
}
