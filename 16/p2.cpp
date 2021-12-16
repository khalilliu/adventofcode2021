#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long LL;
unordered_map<char, string> mp = {
  {'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
  {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
  {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
  {'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"},
};

int get(string &s, int k) {
  int ans = 0;
  for(int i=0; i<k; i++) {
    ans = (ans << 1) + (s[i] - '0');
  }
  s = s.substr(k);
  return ans;
}


LL getVal(string &s) {
  LL res = 0;
  int k;
  while(true) {
    k = get(s, 5);
    if((k >> 4 & 1) == 0) break;
    res = (res << 4) + (k & 15);
  }
  res = (res << 4) + (k & 15);
  return res;
}

LL parse(string &s) {
    get(s, 3);
    int typ = get(s, 3);

    if(typ == 4) {
        return getVal(s);
    } 

    int lid = get(s, 1);

    vector<LL> nums;

    if(lid == 0) {
        int a = get(s, 15);
        string sub = s.substr(0, a);
        s = s.substr(a);

        while(!sub.empty()) {
            nums.push_back(parse(sub));
        }
    } else if(lid == 1) {
        int a = get(s, 11);
        for(int i=0; i<a; i++) {
            nums.push_back(parse(s));
        }
    }

    if(typ == 0) {
        LL res = 0;
        for(auto &v : nums) res += v;
        return res;
    } else if(typ == 1) {
        LL res = 1;
        for(auto &v : nums) res *= v;
        return res;
    } else if(typ == 2) {
        LL res = 1e18;
        for(auto &v : nums) res = min(res, v);
        return res;
    } else if(typ == 3) {
        LL res = 0;
        for(auto &v : nums) res = max(res, v);
        return res;
    } else if(typ == 5) {
        return nums[0] > nums[1] ? 1 : 0;
    } else if(typ == 6) {
        return nums[0] < nums[1] ? 1 : 0; 
    } else if(typ == 7) {
        return nums[0] == nums[1] ? 1 : 0;
    }
    return 0;
}


int main() {
    string s;
    cin >> s;
    string res;
    for(auto &c : s) res += mp[c];
    LL ans = parse(res);
    printf("%lld\n", ans);
    return 0;
}

