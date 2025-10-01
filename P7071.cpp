#include <iostream>
using namespace std;

void solve(int n) {
    if (n == 0) return;
    int lowbit = n & -n;
    solve(n ^ lowbit);
    cout << lowbit << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    if (n & 1) {
        cout << -1 << "\n";
    } else {
        solve(n);
        cout << "\n";
    }
    
    return 0;
}
