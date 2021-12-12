#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_set<string> visited;
unordered_map<string, vector<string>> g;
string st = "start", ed = "end";
int ans;

bool is_large(char &c) {
  return c >= 'A' && c <= 'Z';
}

void split(string &str) {
  string a, b;
  int i=0;
  while(i < str.size()) {
    if(str[i] == '-') break;
    i++;
  }
  a = str.substr(0, i), b = str.substr(i+1);
  cout << a << ' ' << b << endl;
  g[a].push_back(b), g[b].push_back(a);
}

void dfs(string &u) {
  if(u == ed) {
    ans++;
    return;
  }
  if(!is_large(u[0])) visited.insert(u);
  for(auto &v : g[u]) {
    if(visited.count(v)) continue;
    dfs(v);
  }
  visited.erase(u);
}

int main() {
  string str;
  while(getline(cin, str)) {
    split(str);
  }
  dfs(st);
  cout << ans << endl;
  return 0;
}