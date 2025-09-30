#include <iostream>

using namespace std;

int main() {

  long long N, M;
  cin >> N >> M;

  int base = N / M;
  int num = N % M;

  for (int i = 0; i < M - num; ++i) {
    cout << base << " ";
  }

  for (int i = 0; i < num; ++i) {
    cout << base + 1 << " ";
  }
  cout << endl;

  return 0;
}
