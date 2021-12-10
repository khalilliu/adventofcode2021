#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map> 
#include <stack>
#include <vector>

using namespace std;
typedef long long LL;
const int N = 110;
unordered_map<char, int> pts{{'(', 1}, {'[', 2}, {'{', 3}, {'<', 4}};
unordered_map<char, char> pirs{{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};
string s[N];
vector<LL> res;
int n;


LL solve(string &str) {
  int m = str.size();
  stack<char> stk;
  for(auto &c : str) {
    if(pirs.count(c)) {
      if(stk.empty() || stk.top() != pirs[c]) {
        return 0;
      } else stk.pop();
    } else stk.push(c);
  }
  LL ans = 0;
  while(stk.size()) {
    auto c = stk.top(); stk.pop();
    ans = ans * 5 + pts[c];
  }
  return ans;
}

int main() {
  string str;
  while(getline(cin, str)) {
    s[n++] = str;
  }
  for(int i=0; i<n; i++) {
    LL t = solve(s[i]);
    if(t) res.push_back(t);
  }
  int m = res.size();
  nth_element(res.begin(), res.begin() + m/2, res.end());
  cout << res[m/2] << endl;
  return 0;
}