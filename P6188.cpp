#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int mmin = 0;
    int mmax = -1;
    int resa = n, resb = n, resc = n;

    int pric, c;
    for (int a = 0; a <= n / 7; ++a) {
        for (int b = 0; b <= (n - 7 * a) / 4; ++b) {
           pric = n - 7 * a - 4 * b;
           c = pric / 3;
           if( 3 * c == pric){
                if( min(a, min(b, c)) > mmin){
                    resa = a;
                    resb = b;
                    resc = c;
                    mmin = min(a, min(b, c));
                    continue;
                }
                if( a + b + c > mmax){
                    resa = a;
                    resb = b;
                    resc = c;
                    mmax = a + b + c;
                }

             // cout << a << " " << b << " " << c << " " << mmin << " " << mmax << endl;
           }

        }
    }

    if(resa == n || resb == n || resc == n)
        cout << -1;
    else
        cout << resa << " " << resb << " " << resc;
    return 0;
}