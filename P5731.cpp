#include <cstdio>
#include <iostream>

using namespace std;

int diry[] = {1, 0, -1, 0};
int dirx[] = {0, 1, 0, -1};

int main() {

  int n;
  int a[10][10] = {};
  cin >> n;

  int dir = 0;
  int times = n * n;
  int cur = 0, idx = 0, idy = 0;

  a[0][0] = ++cur;

  while (cur < times) {
    if (idx + dirx[dir] >= 0 && idx + dirx[dir] < n && idy + diry[dir] >= 0 &&
        idy + diry[dir] < n && a[idx + dirx[dir]][idy + diry[dir]] == 0) {

      idx += dirx[dir];
      idy += diry[dir];

      a[idx][idy] = ++cur;

    } else {
      dir = (dir + 1) % 4;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%3d", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
