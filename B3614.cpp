/*
#include <iostream>
using namespace std;

int main(){



}
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  string s;
  cin >> t;
  unsigned long long x;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    stack<unsigned long long> st;
    for (int j = 0; j < n; j++) {
      cin >> s;
      if (s == "push") {
        cin >> x;
        st.push(x);
      } else if (s == "pop") {
        if (st.empty()) {
          cout << "Empty" << endl;
        } else {
          st.pop();
        }
      } else if (s == "query") {
        if (st.empty()) {
          cout << "Anguei!" << endl;
        } else {
          cout << st.top() << endl;
        }
      } else if (s == "size") {
        cout << st.size() << endl;
      }
    }
  }

  return 0;
}
