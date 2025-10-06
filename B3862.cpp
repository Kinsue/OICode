#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> edge;
vector<vector<int>> adj;

vector<bool> vis;

//  邻接矩阵
void create_adj() {

  adj.resize(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
  }
}

int dfs_adj(int u) {

  vis[u] = true;
  int max_node = u;

  for (int v = 1; v <= n; ++v) {
    if (adj[u][v] == 1 && !vis[v]) {
      max_node = max(max_node, dfs_adj(v));
    }
  }

  return max_node;
}

int bfs_adj(int u) {

  int max_node = u;

  queue<int> q;
  q.push(u);

  while (!q.empty()) {
    int node = q.front();
    vis[node] = true;
    q.pop();
    for (int v = 1; v <= n; ++v) {
      if (adj[node][v] == 1 && !vis[v]) {
        q.push(v);
        max_node = max(max_node, v);
      }
    }
  }
  return max_node;
}

void solve_adj(string fun) {

  vis.resize(n + 1, false);
  for (int i = 1; i <= n; ++i) {
    vis.assign(n + 1, false);
    if (fun == "dfs")
      cout << dfs_adj(i) << " ";
    else
      cout << bfs_adj(i) << " ";
  }
}

// 邻接表
void create_table() {
  edge.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
  }
}

int dfs_table(int u) {

  vis[u] = true;
  int max_node = u;

  for (auto v : edge[u]) {
    if (!vis[v]) {
      max_node = max(max_node, dfs_table(v));
    }
  }

  return max_node;
}

int bfs_table(int u) {

  int max_node = u;

  queue<int> q;
  q.push(u);

  while (!q.empty()) {
    int node = q.front();
    vis[node] = true;
    q.pop();
    for (auto v : edge[node]) {
      if (!vis[v]) {
        q.push(v);
        max_node = max(max_node, v);
      }
    }
  }
  return max_node;
}

void solve_table(string fun) {

  vis.resize(n + 1, false);
  for (int i = 1; i <= n; ++i) {
    vis.assign(n + 1, false);
    if (fun == "dfs")
      cout << dfs_table(i) << " ";
    else
      cout << bfs_table(i) << " ";
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
