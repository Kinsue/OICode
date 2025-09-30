#include <iostream>

using namespace std;

const int N = 1e5 + 2;
int NUM[N];

void prime() {

  int idx = 2;
  NUM[1] = 1;
  while (idx < N) {
    while (NUM[idx])
      idx++;
    for (int i = 2 * idx; i <= N; i += idx) {
      NUM[i] = 1;
    }
    idx++;
  }
}

int main() {
  int n;
  cin >> n;
  prime();

  for (int i = 2; i * i <= n; ++i) {
    if (!NUM[i] && n % i == 0) {
      cout << n / i << endl;
    }
  }

  return 0;
}
