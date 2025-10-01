#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n, m, t;
vector<pair<string, int>> gate;
string op;

int calc(int k) {

  int pos = 1;
  int neg = 0;

  for (auto item : gate) {
    if (item.first == "AND") {
      pos &= item.second >> k & 1;
      neg &= item.second >> k & 1;
    }

    if (item.first == "OR") {
      pos |= item.second >> k & 1;
      neg |= item.second >> k & 1;
    }

    if (item.first == "XOR") {
      pos ^= item.second >> k & 1;
      neg ^= item.second >> k & 1;
    }
  }

  return (pos == 1 && neg == 0);
  // return (neg < pos);
}

int main() {

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> op >> t;
    gate.push_back(make_pair(op, t));
  }

  int num = 0;

  for (int i = 29; i >= 0; --i) {
    if (num + (1 << i) <= m && calc(i)) {
      num += (1 << i);
    }
  }

  for (auto item : gate) {
    if (item.first == "AND")
      num &= item.second;

    if (item.first == "OR")
      num |= item.second;

    if (item.first == "XOR")
      num ^= item.second;
  }

  cout << num << endl;

  return 0;
}
