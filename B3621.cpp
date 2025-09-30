#include <cstring>
#include <iostream>

using namespace std;

int n, k;
int a[10];

void dfs(int idx) {

  if (idx == n + 1) {
    for (int i = 1; i <= n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = 1; i <= k; ++i) {
    a[idx] = i;
    dfs(idx + 1);
  }
}

int main() {

  cin >> n >> k;
  memset(a, 0, sizeof(a));

  dfs(1);

  return 0;
}
