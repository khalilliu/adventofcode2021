#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;
typedef long long LL;

const LL INF = 1e18;

unordered_map<string,string> mp;
unordered_map<string, LL> cur, tmp;
string start;
LL cnt[26];
int n;

int main() {
    string s;
    cin >> start;
    getline(cin, s);
    while(getline(cin, s)) {
        char a[5], b[5];
        sscanf(s.c_str(), "%s -> %s", a, b);
        mp[string(a)] = string(b);
    }

    n = start.size();
    for(int i=0; i<n-1; i++) cur[start.substr(i, 2)]++;

    int T = 40;
    while(T--) {
        tmp.clear();
        for(auto &p : cur) {
            if(mp.count(p.first)) {
                tmp[p.first[0] + mp[p.first]] += p.second;
                tmp[mp[p.first] + p.first[1]] += p.second;
            } else tmp[p.first] = p.second;
        }
        cur = tmp;
    }

    for(auto &p : cur) {
        cnt[p.first[0] - 'A'] += p.second;
    }

    cnt[start[n-1]-'A'] ++;

    LL minv = INF, maxv = 0;
    for(int i=0; i<26; i++) {
        if(cnt[i] == 0) continue;
        minv = min(minv, cnt[i]);
        maxv = max(maxv, cnt[i]);
    }

    printf("answer is equal to %lld\n", maxv - minv);
    return 0;

}
