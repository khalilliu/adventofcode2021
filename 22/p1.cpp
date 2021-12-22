#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, L = 1, R = 102;

int pre[N][N][N];
int a1, a2, b1, b2, c1, c2;
char statue[10];

int get(int x) {
    return x + 51;
}

void solve() {
    // cout << statue << ' ' << a1 << a2 << b1 << b2 << c1 << c2 << endl;
    
    if(a1 > R || a2 < L || b1 > R || b2 < L || c1 > R || c2 < L ) return;
    int t = string(statue) == "on" ? 1 : 0;
    for(int i=a1; i<=a2; i++) {
        for(int j=b1; j<=b2; j++) {
            for(int k=c1; k<=c2; k++) pre[i][j][k] = t;
        }
    }
}

int main() {
    string s;
    while(getline(cin, s)) {
        sscanf(s.c_str(), "%s x=%d..%d,y=%d..%d,z=%d..%d", statue, &a1, &a2, &b1, &b2, &c1, &c2);
        a1 = get(a1), a2 = get(a2), b1 = get(b1), b2 = get(b2), c1 = get(c1), c2 = get(c2);
        solve();
    }
    
    int ans = 0;
    for(int i=L; i<=R; i++) {
        for(int j=L; j<=R; j++) {
            for(int k=L; k<=R; k++) {
                ans += (pre[i][j][k] == 1);
            }
        }
    }
     cout << ans << endl;
    return 0;
}



