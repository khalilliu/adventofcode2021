#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long LL;

unordered_map<string, string> dict;
unordered_map<string, LL> pirs, tmp;
const LL INF = 1e18;
string start;

int main() {
    string s;
    getline(cin, start);
    getline(cin, s);
    while(getline(cin, s)) {
        char a[5], b[5];
        sscanf(s.c_str(), "%s -> %s", a, b);
        dict[string(a)] = string(b);
    }

    for(int i=0; i<start.size()-1; i++) {
        pirs[start.substr(i,2)] ++;
    }

    for(int step = 0; step < 40; step++) {
        tmp.clear();
        for(auto &p : pirs) {
            string k = p.first;
            LL v = p.second;
            auto t1 = k[0] + dict[k];
            auto t2 = dict[k] + k[1];
            tmp[t1] += v, tmp[t2] += v;
        }
        pirs = tmp;
    }

    unordered_map<int, LL> cnt;

    for(auto &p : pirs) {
        string k = p.first;
        LL v = p.second;
        cnt[k[0] - 'A'] += v;  
    }

    cnt[start[start.size()-1] - 'A']++;

    LL minv = INF, maxv = 0;
    for(auto &p : cnt) {
        LL v = p.second;
        minv = min(v, minv);
        maxv = max(v, maxv);
    }
    cout << maxv - minv << endl;

    return 0;
}
