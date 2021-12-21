#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

const int N = 30;
LL p1, p2;
PLL f[N][N][N][N];

PLL dp(int p1, int p2, int st1, int st2) {
    if(st1 >= 21) return {1, 0};
    if(st2 >= 21) return {0, 1};
    if(f[p1][p2][st1][st2] != PLL{0, 0}) return f[p1][p2][st1][st2];
    
    PLL ans = {0, 0};
    for(int d1=1; d1<=3; d1++){
        for(int d2=1; d2<=3; d2++){
            for(int d3=1; d3<=3; d3++){
                int new_p1 = (p1 + d1 + d2 + d3)%10;
                int new_st1 = new_p1 + st1 + 1;
                
                auto t = dp(p2, new_p1, st2, new_st1);
                ans = {ans.first + t.second, ans.second + t.first};
            }
        }
    }
    
    return f[p1][p2][st1][st2] = ans;
}

int main() {
    string s1, s2;
    getline(cin, s1), getline(cin, s2);
    p1 = s1[s1.size()-1] - '0', p2 = s2[s2.size()-1] - '0';

    p1--, p2--;

    auto t = dp(p1, p2, 0, 0);

    cout << max(t.first, t.second) << endl;

    return 0;
}
