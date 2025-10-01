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

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      proc.push_back(a[i] + b[j]);
    }
  }

  sort(proc.begin(), proc.end());

  for (int i = 0; i < n; ++i)
    cout << proc[i] << " ";

  return 0;
}
