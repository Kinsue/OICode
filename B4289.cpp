#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;

  vector<char> vec(n);

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  sort(vec.begin(), vec.end());

  for (auto item : vec)
    cout << item;

  return 0;
}
