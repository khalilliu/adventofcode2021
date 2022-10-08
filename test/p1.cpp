#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;
char s[300][300];
int dist[300][300];

void solve() {
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m;
    queue<PII> q;
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
        if(s[i][j] == '1') {
            q.push({i, j});
            dist[i][j] = 0;
        }
    }

    while(q.size()) {
        auto [x, y] = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m) continue;
            if(dist[a][b] > dist[x][y] + 1) {
                dist[a][b] = dist[x][y] + 1;
                q.push({a, b});
            }
        }
    }
    

    int l = 0, r = m+n;
    while(l < r) {
        int mid = (l + r) >> 1;
        vector<PII> pts;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dist[i][j] > mid) pts.push_back({i, j});
            }
        }
        int mx1 = -1e9, mx2 = -1e9, mn1 = 1e9, mn2 = 1e9;
        for(auto [x, y] : pts) {
            mx1 = max(mx1, x + y);
            mx2 = max(mx2, x - y);
            mn1 = min(mn1, x + y);
            mn2 = min(mn2, x - y);
        }
        bool flag = false;
        if(pts.size() == 0) flag = true;
        for(int x=0;x<n;x++)for(int y=0; y<m;y++){
            int k = max({abs(x+y-mx1), abs(x+y-mn1), abs(x-y-mx2), abs(x-y-mn2)});
            if(k <= mid) {
                flag = true;
                break;
            }
        }
        if(flag) {
            r = mid;
        } else l = mid + 1;
    }
    cout << r << endl;
}

int main() {
    int T;
    cin >> T;
    for(int tcase=1; tcase <= T; tcase++) {
        printf("Case #%d: ", tcase);
        solve();
    }
    
    return 0;
}