#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n;
vector<vector<int>> vec(2 * 1e5 + 5);
vector<bool> flag(2 * 1e5 + 5, 0);

void dfs(int v) {

  flag[v] = true;

  for (auto item : vec[v]) {
    if (!flag[item])
      dfs(item);
  }
}

int main() {

  cin >> n;

  int cnt = 0;
  int a, b;

  for (int i = 1; i <= n; ++i) {
    cin >> a >> b;

    if (a == 0 || b == 0) {
      vec[0].push_back(i);
      continue;
    }

    vec[a].push_back(i);
    vec[b].push_back(i);
  }

  // auto dfs = [&](auto self, int v) -> void {
  //   flag[v] = 1;
  //   for (auto node : vec[v]) {
  //     if (flag[node] == 0) {
  //       self(self, node);
  //     }
  //   }
  // };

  flag[0] = 1;
  dfs(0);

  for (auto item : flag)
    if (item)
      cnt++;

  cout << cnt - 1 << endl;

  return 0;
}
