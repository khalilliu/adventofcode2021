#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define x first
#define y second

using namespace std;
typedef pair<int, int>PII;
const int N = 550, INF = 1e9;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int g[N][N], dist[N][N];
bool st[N][N];
queue<PII> q;
int n, m;

void split(string &s) {
  if(!m) m = s.size();
  for(int i=0; i<m; i++) {
    g[n][i] = s[i] - '0';
  }
  n++;
}

void print() {
  for(int i=0; i<n*5; i++) {
    for(int j=1; j<m*5; j++) {
      cout << g[i][j];
    }
    cout << endl;
  }
}

int get(int x, int y) {
    int t = g[x%n][y%m] + x/n + y/m;
    return t > 9 ? t%9 : t;
}

void init() {
  string s;
  while(getline(cin, s)) {
    split(s);
  }
}

void spfa() { 
  memset(dist, 0x3f, sizeof dist);
  q.push({0, 0});
  dist[0][0] = 0;
  st[0][0] = true;
  while(q.size()) {
    auto t = q.front(); q.pop();
    st[t.x][t.y] = false;
    for(int i=0; i<4; i++) {
      int a = t.x + dx[i], b = t.y + dy[i];
      if(a < 0 || a >= n*5 || b < 0 || b >= m*5) continue;
      if(dist[a][b] > dist[t.x][t.y] + get(a, b)) {
        dist[a][b] = dist[t.x][t.y] + get(a, b);
        if(!st[a][b]) {
          q.push({a, b});
          st[a][b] = true;
        }
      }
    }
  }
} 


int main() {
  init();
  spfa();
  cout << dist[n*5-1][m*5-1] << endl;
  return 0;
}
