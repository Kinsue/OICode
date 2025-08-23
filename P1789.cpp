#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int mmap[111][111];
int n;

void huo(int x, int y){
    for(int i = -2; i <= 2; ++i){
        for(int j = -2; j <= 2; ++j){
            if( x + i > 0 && x + i <= n &&
                y + j > 0 && y + j <= n && 
                abs(i) + abs(j) <= 2){
                    mmap[x + i][y + j] = 1;
                }
        }
    }

}

void yin(int x, int y){
    for(int i = -2; i <= 2; ++i){
        for(int j = -2; j <= 2; ++j){
            if( x + i > 0 && x + i <= n &&
                y + j > 0 && y + j <= n){
                    mmap[x + i][y + j] = 1;
                }
        }
    }
}

int main(){

    int m, k;
    int x, y;
    cin >> n >> m >> k;

    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        huo(x, y);
    }

    for(int i = 0; i < k; ++i){
        cin >> x >> y;
        yin(x, y);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            // cout << mmap[i][j] << " ";
            if( mmap[i][j] == 0){
                ans ++;
            }
        }
        // cout << endl;

    }

    cout << ans << endl;

    return 0;
}

