#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main(){

    int m[1002] = {};
    int N, D;
    int tmp;
    cin >> N >> D;

    for(int i = 1; i <= D; ++i){
        cin >> tmp;

        m[tmp] += i;
    }

    for(int i = 0; i < N; ++i){
        if(i){
            cout << " " << m[i];
        }else{
            cout << m[i];
        }
    }

    return 0;
}

