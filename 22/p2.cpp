#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
int a1, a2, b1, b2, c1, c2;
vector<int> numsA, numsB, numsC;
vector<PII> A, B, C;
vector<int> st;
char statue[10];

int get(int x, vector<int> &nums) {
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}


int main() {
    string s;
    while(getline(cin, s)) {
        sscanf(s.c_str(), "%s x=%d..%d,y=%d..%d,z=%d..%d", statue, &a1, &a2, &b1, &b2, &c1, &c2);
        if(a1 > a2) swap(a1, a2);if(b1 > b2) swap(b1, b2);if(c1 > c2) swap(c1, c2);
        numsA.push_back(a1), numsA.push_back(a2+1), numsB.push_back(b1), numsB.push_back(b2+1), numsC.push_back(c1), numsC.push_back(c2+1);
        A.push_back({a1, a2+1}), B.push_back({b1, b2+1}), C.push_back({c1, c2+1});
        st.push_back(int(string(statue) == "on"));
    }
    sort(numsA.begin(), numsA.end());
    sort(numsB.begin(), numsB.end());
    sort(numsC.begin(), numsC.end());
    numsA.erase(unique(numsA.begin(), numsA.end()), numsA.end());
    numsB.erase(unique(numsB.begin(), numsB.end()), numsB.end());
    numsC.erase(unique(numsC.begin(), numsC.end()), numsC.end());

    int N = numsA.size(), M = numsB.size(), K = numsC.size();
    vector<vector<vector<int>>> g(N, vector<vector<int>>(M, vector<int>(K, 0)));

    for(int i=0; i<st.size(); i++) {
        int a1 = get(A[i].first, numsA), a2 = get(A[i].second, numsA); 
        int b1 = get(B[i].first, numsB), b2 = get(B[i].second, numsB); 
        int c1 = get(C[i].first, numsC), c2 = get(C[i].second, numsC); 
        for(int x=a1; x<a2; x++) {
            for(int y=b1; y<b2; y++) {
                for(int z=c1; z<c2; z++) {
                    g[x][y][z] = st[i];
                }
            }
        }
    }

    LL ans = 0;     

    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M-1; j++ ){
            for(int k=0; k<K-1; k++) {
                if(g[i][j][k] == 0) continue;
                ans += (LL)g[i][j][k] * (numsA[i+1]-numsA[i]) * (numsB[j+1]-numsB[j]) * (numsC[k+1]-numsC[k]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}

