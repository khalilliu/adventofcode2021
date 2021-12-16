#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <unordered_map>

using namespace std;
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

int getVersion(string &s) {
  return get(s, 3);
}

int getType(string &s) {
  return get(s, 3);
}

int getVarint(string &s) {
  int res = 0, k;
  do {
    k = get(s, 5);
    res = (res << 4) + (k & 0xF);
  } while(k & 0x10);
  return res;
}

int parse(string &s) {
  int ver = getVersion(s);
  int typ = getType(s);

  int sum = ver;
  if(typ == 4) {
    getVarint(s);
  } else {
    int lid = get(s, 1);
    printf("lid : %d\n", lid);
    if(lid == 0) {
      int a = get(s, 15);
      printf("length of sub-packet: %d\n", a);
      string sub = s.substr(0, a);
      s = s.substr(a);
      while(!sub.empty()) {
        sum += parse(sub);
      }
    } else if(lid == 1) {
      int a = get(s, 11);
      for(int i=0; i<a; i++) {
        sum += parse(s);
      }
    }
  }
  return sum;
}


int main() {
  string s;
  cin >> s;
  string res;
  for(auto &c : s) res += mp[c];
  cout << res << endl;
  int ans = parse(res);
  cout << ans << endl;
  return 0;
}

