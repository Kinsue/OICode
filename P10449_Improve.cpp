#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    int grid[5] = {0};

    // 读入数据并转换为位表示
    for (int i = 0; i < 5; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < 5; j++) {
        if (s[j] == '1') {
          grid[i] |= (1 << j);
        }
      }
    }

    int ans = 7;

    // 枚举第一行的32种状态
    for (int mask = 0; mask < 32; mask++) {
      int temp[5];
      memcpy(temp, grid, sizeof(grid));

      int steps = __builtin_popcount(mask);

      // 处理第一行操作
      for (int j = 0; j < 5; j++) {
        if (mask & (1 << j)) {
          // 切换(0,j)及其相邻位置
          temp[0] ^= (1 << j);
          if (j > 0)
            temp[0] ^= (1 << (j - 1));
          if (j < 4)
            temp[0] ^= (1 << (j + 1));
          if (1 < 5)
            temp[1] ^= (1 << j);
        }
      }

      // 贪心处理第2-5行
      for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          if (!(temp[i - 1] & (1 << j))) { // 上一行第j位是0
            steps++;
            // 切换(i,j)及其相邻位置
            temp[i] ^= (1 << j);
            if (j > 0)
              temp[i] ^= (1 << (j - 1));
            if (j < 4)
              temp[i] ^= (1 << (j + 1));
            temp[i - 1] ^= (1 << j);
            if (i + 1 < 5)
              temp[i + 1] ^= (1 << j);
          }
        }
      }

      // 检查最后一行是否全为1 (31 = 11111二进制)
      if (temp[4] == 31) {
        ans = min(ans, steps);
      }
    }

    cout << (ans == 7 ? -1 : ans) << '\n';
  }

  return 0;
}
