#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> vec(n);
  vector<int> diff;

  for (int i = 0; i < n; ++i)
    cin >> vec[i];

  for (int i = 1; i < n; ++i) {
    diff.push_back(abs(vec[i] - vec[i - 1]));
  }

  sort(diff.begin(), diff.end());

  for (int i = 0; i < n - 1; ++i) {
    if (diff[i] != i + 1) {
      cout << "Not jolly" << endl;
      return 0;
    }
  }

  cout << "Jolly" << endl;
  return 0;
}
