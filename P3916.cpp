#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> edge;
vector<vector<int>> adj;

vector<int> vis;

// 邻接表
void create_table() {
  edge.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edge[v].push_back(u);
  }
}

void dfs_table(int u, int fa) {

  if (vis[u] != -1)
    return;

  vis[u] = fa;

  for (auto v : edge[u]) {
    if (vis[v] == -1) {
      dfs_table(v, fa);
    }
  }
}

void bfs_table(int u, int fa) {

  if (vis[u] != -1)
    return;

  queue<int> q;
  q.push(u);

  while (!q.empty()) {

    int node = q.front();
    q.pop();
    vis[node] = fa;

    for (auto v : edge[node]) {
      if (vis[v] == -1) {
        q.push(v);
      }
    }
  }
}

void solve_table(string fun) {

  vis.resize(n + 1, -1);
  for (int i = n; i; --i)
    if (fun == "dfs")
      dfs_table(i, i);
    else
      bfs_table(i, i);

  for (int i = 1; i <= n; ++i) {
    cout << vis[i] << " ";
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  create_table();
  // solve_table("dfs");
  solve_table("bfs");

  // create_adj();
  // // solve_adj("dfs");
  // solve_adj("bfs");

  return 0;
}
