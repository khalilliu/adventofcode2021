#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
vector<string> g;
set<PII> l_set, d_set;
int n, m;

void read_input() {
    string s;
    while(getline(cin, s)) {
        g.push_back(s);
    }
    n = g.size(), m = g[0].size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
           char t = g[i][j];
           if(t == 'v') d_set.insert({i, j});
           else if(t == '>') l_set.insert({i, j});
        }
    }
}

int main() {
    read_input();
    int ans = 1;
    while(true) {
        bool has_moved = false;
        set<PII> tmp_left, tmp_down;
        for(auto &l : l_set) {
            int x = l.x, y = l.y;
            PII t = {x, (y + 1)%m};
            if(l_set.count(t) || d_set.count(t)) tmp_left.insert(l);
            else tmp_left.insert(t), has_moved = true;
        }
        l_set = tmp_left;
        for(auto &d : d_set) {
            int x = d.x, y = d.y;
            PII t = {(x+1)%n, y};
            if(l_set.count(t) || d_set.count(t)) tmp_down.insert(d);
            else tmp_down.insert(t), has_moved = true;
        }
        d_set = tmp_down;
        if(!has_moved) break;

        ans++;
    };
    cout << ans << endl;
    return 0;
}
