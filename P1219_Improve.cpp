#include <bits/stdc++.h>

using namespace std;

int row[14];
int ans = 0;
int n;

// using flag instead of for-loop to save judging time
//
int ltrd[28], rtld[28];
int line[14];

// bool check(int r) {
//   for (int i = 1; i < r; ++i) {
//     if (i + row[i] == r + row[r] || i - row[i] == r - row[r] ||
//         row[r] == row[i])
//       return false;
//   }
//   return true;
// }

void print() {
  for (int i = 1; i <= n; ++i) {
    cout << row[i];
    if (n)
      cout << " ";
  }
  cout << endl;
}

void fun(int idx) {

  if (idx == n + 1) {
    ans++;
    if (ans < 4)
      print();
    return;
  }

  for (int i = 1; i <= n; ++i) {

    row[idx] = i;

    if (!(line[i] || rtld[idx + i] || ltrd[n - i + idx])) {
      line[i] = 1;
      rtld[idx + i] = 1;
      ltrd[n - i + idx] = 1;

      fun(idx + 1);

      line[i] = 0;
      rtld[idx + i] = 0;
      ltrd[n - i + idx] = 0;
    }
  }
}

int main() {

  cin >> n;

  row[1] = 1;
  fun(1);

  cout << ans;

  return 0;
}
