#include <bits/stdc++.h>
#include <climits>

using namespace std;

struct NodeStar {
  int weight;
  int to;
  int next;
};

int n, m, s;

// 链式前向星
vector<NodeStar> edge;
vector<int> head;

// 邻接表
vector<vector<pair<int, int>>> edge_table;

void dijkstra_star() {

  vector<int> dis(n + 1, INT_MAX);
  vector<bool> visited(n + 1, false);

  dis[s] = 0;

  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  pq.push({0, s});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    if (visited[u]) {
      continue;
    }
    visited[u] = true;

    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      int w = edge[i].weight;

      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        pq.push({dis[v], v});
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (dis[i] == INT_MAX) {
      cout << INT_MAX << " ";
    } else {
      cout << dis[i] << " ";
    }
  }
  cout << endl;
}

void create_graph_star() {

  int u, v, w;

  head.resize(n + 1, -1);

  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    edge.push_back({w, v, head[u]});
    head[u] = i;
  }
}

void create_graph_table() {

  edge_table.resize(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edge_table[u].push_back({v, w});
  }
}

void dijkstra_table() {
  vector<int> dis(n + 1, INT_MAX);
  vector<bool> visited(n + 1, false);
  dis[s] = 0;

  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  pq.push({0, s});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    if (visited[u]) {
      continue;
    }
    visited[u] = true;

    for (auto const &edge : edge_table[u]) {
      int v = edge.first;
      int w = edge.second;

      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        pq.push({dis[v], v});
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (dis[i] == INT_MAX) {
      cout << INT_MAX << " ";
    } else {
      cout << dis[i] << " ";
    }
  }
  cout << endl;
}

int main() {

  cin >> n >> m >> s;
  create_graph_star();
  dijkstra_star();
}
