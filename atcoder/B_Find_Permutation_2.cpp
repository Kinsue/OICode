#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> flag(n + 1, 0);
    vector<int> ans(n + 1, 0);
    stack<int> num;

    int tmp, mul= 0;

    for(int i = 1; i <= n; ++i){
        cin >> tmp;
        if(tmp == -1) continue;

        flag[tmp] ++;
        ans[i] = tmp;
        if( flag[tmp] > 1)
            mul = 1;
    }

    if(mul){
        cout << "No";
        return 0;
    }else{
        cout << "Yes\n";
    }

    for(int i = 1; i <= n; ++i){
        if(flag[i] == 0)
            num.push(i);
    }

    for(int i = 1; i <= n; ++i){
        if(ans[i] == 0)
            ans[i] = num.top(), num.pop();
    }

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";

    return 0;
}