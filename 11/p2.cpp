#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define x first
#define y second

using namespace std;
typedef pair<int, int>PII;
const int N = 15;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int g[N][N];
bool st[N][N];
int n, m;

void split(string &s) {
  if(!m) m = s.size();
  for(int i=0; i<s.size(); i++) {
    g[n][i] = s[i] - '0';
  }
  n++;
}

void print() {
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) {
      cout << g[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  string str;
  while(getline(cin, str)) {
    split(str);
  }
  print();
  int res = 1;
  while(true) {
    memset(st, 0, sizeof st);
    queue<PII> q;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        g[i][j] += 1;
        if(g[i][j] == 10) q.push({i, j});
      }
    }
    while(q.size()) {
      auto t =  q.front(); q.pop();
      st[t.x][t.y] = true, g[t.x][t.y] = 0;
      for(int i=0; i<8; i++) {
        int a = t.x + dx[i], b = t.y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]) continue;
        g[a][b] ++ ;
        if(g[a][b] == 10) q.push({a, b}), st[a][b] = true;
      }
    }
    bool flag = true;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if(!st[i][j]) flag = false;
      }
    }
    if(flag) break;
    res ++;
  }

  cout << res << endl;
  return 0;
}