#include<bits/stdc++.h>

using namespace std;

void std_solve(){
    int T;
    int na, nb, nc;
    cin >> T;

    while(T--){
        cin >> na >> nb >> nc;
    
        int result = 0;
        int tmp;

        cout << min({na, nc, (na + nb + nc) / 3}) << endl;
    
    }
}

void binary_solve(){

    int T;
    int na, nb, nc;
    cin >> T;

    while(T--){
        cin >> na >> nb >> nc;
    
        int Lb = 0, Rb = INT_MAX / 2;
        int m;

        while(Rb - Lb >= 1){
            m = Lb + (Rb - Lb) / 2;

            // cout << Lb << "< " << m << ">" << Rb << " .";

            if(na >= m && nc >= m && (na + nc - 2 * m + nb) >= m){
                Lb = m + 1;
            }else{
                Rb = m;
            }

        }
        cout << Lb - 1 << endl;
    }
}

int main(){

    // std_solve();
    binary_solve();

    return 0;
}