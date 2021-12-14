#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, string> dict;
int cnt[26];
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
    
   // for(auto v : dict) cout << v.first << ' ' << v.second << endl;
        
    string cur = start, tmp = "";
    for(int step=0; step<10; step++) {
        for(int i=0; i<cur.size()-1; i++) {
            tmp += cur[i];
            string t = cur.substr(i,2);
            if(dict.count(t)) tmp += dict[t];
            if(i == cur.size()-2) tmp += cur[cur.size()-1];
        }
        cur = tmp, tmp = "";
        if(step < 4) cout << cur << endl;
    }
    
    
    for(auto &c : cur) {
        cnt[c-'A']++;
    }

    int minv = 10000010, maxv = 0;
    for(int i=0; i<26; i++) {
        if(cnt[i] == 0) continue;
        minv = min(cnt[i], minv);
        maxv = max(cnt[i], maxv);
    }

    cout << maxv - minv << endl;

    return 0;
}
