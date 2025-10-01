#include<bits/stdc++.h>

using namespace std;

int main(){

    
    int n, m;
    cin >> n >> m;

    vector<long long> vec((n + 1) << 1, 0);
    vector<long long> pre((n + 1) << 1, 0);

    for(int i = 1; i <= n; ++i){
        cin >> vec[i];
        vec[i + n] = vec[i];
    }

    for(int i = 1; i <= 2 * n; ++i)
        pre[i] = pre[i - 1] + vec[i];

    int op;
    int c, L, R;
    int idx = 0;

    for(int i = 0; i < m; ++i){
        cin >> op;
        if(op == 1){
            cin >> c;
            idx = (idx + c) % n;
        }else{
            cin >> L >> R;
            cout << pre[R + idx] - pre[L + idx - 1] << endl;
        }
    }



    return 0;
}