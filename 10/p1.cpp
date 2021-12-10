#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map> 
#include <stack>

using namespace std;
const int N = 110;
unordered_map<char, int> pts{{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
unordered_map<char, char> pirs{{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};
string s[N];
int n, res;

int check(string &str) {
  int m = str.size();
  stack<char> stk;
  for(auto &c : str) {
    if(pirs.count(c)) {
      if(stk.empty() || stk.top() != pirs[c]) {
        return pts[c];
      } else stk.pop();
    } else stk.push(c);
  }
  return 0;
}

int main() {
  string str;
  while(getline(cin, str)) {
    s[n++] = str;
  }
  for(int i=0; i<n; i++) {
    res += check(s[i]);
  }
  cout << res << endl;
  return 0;
}