#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> a(n), b(n);

  for (int i = 0; i < n; ++i)
    cin >> a[i];

  for (int i = 0; i < n; ++i)
    cin >> b[i];

  sort(a.begin(), a.begin());
  sort(b.begin(), b.end());

  vector<int> proc;

  proc.push_back(a[0] + b[0]);

  for (int i = 1; i < n; ++i) {
    proc.push_back(b[0] + a[i]);
  }
  for (int i = 1; i < n; ++i) {
    proc.push_back(a[0] + b[i]);
  }

  sort(proc.begin(), proc.end());

  for (int i = 1; i <= n; ++i)
    cout << proc[i] << " ";

  return 0;
}
