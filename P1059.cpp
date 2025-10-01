#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;

  vector<int> vec(n);
  vector<int> res;

  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());

  res.push_back(vec[0]);
  for (int i = 1; i < n; ++i) {
    if (vec[i] == res.back())
      continue;
    res.push_back(vec[i]);
  }

  cout << res.size() << endl;
  for (auto item : res)
    cout << item << " ";
  return 0;
}
