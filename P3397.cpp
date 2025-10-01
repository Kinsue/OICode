#include <bits/stdc++.h>
#include <vector>
using namespace std;

int D[1005][1005];

int main() {

  int n, m;
  cin >> n >> m;

  // Dtor<Dtor<int>> pre(n+1, Dtor<int>(n+1, 0));
  memset(D, 0, sizeof(D));

  int x1, y1, x2, y2;
  for (int i = 0; i < m; ++i) {
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    D[x1][y1] += 1;
    D[x2 + 1][y1] -= 1;
    D[x1][y2 + 1] -= 1;
    D[x2 + 1][y2 + 1] += 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      D[i][j] = D[i][j] + D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
      cout << D[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
