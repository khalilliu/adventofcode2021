#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<string>> g;
unordered_map<string, int> small_caves, visited;
string st = "start", ed = "end";
unordered_set<string> path;
vector<string> p;

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
  if(!is_large(a[0])) small_caves[a] = 1;
  if(!is_large(b[0])) small_caves[b] = 1;
  g[a].push_back(b), g[b].push_back(a);
}

void dfs(string &u, vector<string> &p) {
  if(u == ed) {
    string a;
    for(auto &v : p) a += v;
    a += u;
    path.insert(a);
    return;
  }
  p.push_back(u);
  if(!is_large(u[0])) visited[u] --;
  for(auto &v : g[u]) {
    if(!is_large(v[0]) && visited[v] == 0) continue;
    dfs(v, p);
  }
  if(!is_large(u[0])) visited[u]++;
  p.pop_back();
}

int main() {
  string str;
  while(getline(cin, str)) {
    split(str);
  }
  for(auto &cave : small_caves) {
    if(cave.first == st || cave.first == ed) continue;
    visited = small_caves;
    visited[cave.first] = 2;
    dfs(st, p);
  }
  cout << path.size() << endl;
  return 0;
}