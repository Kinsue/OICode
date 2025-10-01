#include <algorithm>
#include<bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dirx[] = {-1, 1, 0,0};
int diry[] = {0, 0, -1,1};

bool solve(int x, int y, const vector<vector<char>> &mmap){
    
    int ct = 0;
    for(int i = 0; i < 4; ++i){
        if(mmap[x + dirx[i]][y + diry[i]] == '#')
            ct ++;
    }
    return ct == 1 ? true : false;
}

int main(){

    int H, W;
    int ans = 0;

    cin >> H >> W;
    vector<vector<char>>  vec(H + 3, vector<char>(W + 3, '.'));
    vector<vector<bool>>  flag(H + 3, vector<bool>(W + 3, false));
    for(int i = 1; i <= H; ++i)
        for(int j = 1; j <= W; ++j){
            cin >> vec[i][j];
        }

    queue<pair<int, int>> que;

    for (int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j){
            if(vec[i][j] == '#')
                ans++, flag[i][j] = true, que.push(make_pair(i, j));
            
        }
    }

    pair<int, int> tmp;
    queue<pair<int, int>> op;
    int idx, idy;
    
    while(!que.empty() || !op.empty()){
        while(!que.empty()){
            tmp = que.front();
            que.pop();

            for(int i = 0; i < 4; ++i){
                idx =  tmp.first + dirx[i];
                idy =  tmp.second + diry[i];


                if( idx > 0 && idx <= H && idy > 0 && idy <= W && solve(idx, idy, vec)){
                    if(flag[idx][idy])  continue;
                    op.push(make_pair(idx, idy));
                    ans ++;
                    flag[idx][idy] = true;
                }

            }
        }
        
        while(!op.empty()){
            tmp = op.front();
            vec[tmp.first][tmp.second] = '#';
            op.pop();
            que.push(tmp);
        }

    }
    cout << ans << endl;
    return 0;
}