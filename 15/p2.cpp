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
  for(int i=1; i<=m; i++) {
    g[n][i] = s[i - 1] - '0';
  }
  n++;
}

void print() {
  for(int i=1; i<=n*5; i++) {
    for(int j=1; j<=m*5; j++) {
      cout << g[i][j];
    }
    cout << endl;
  }
}

void init() {
  n = 1, m = 0;
  string s;
  while(getline(cin, s)) {
    split(s);
  }
  n--;
  for(int i=1; i<=n*5; i++) {
    for(int j=1; j<=m*5; j++) {
      // if(i <= n && j <= m) continue;
      int x = (i-1) % n + 1, y = (j-1)%m + 1;
      int t = g[x][y] + (i-1)/n + (j-1)/m;
      g[i][j] = t > 9 ? t % 9 : t;
    }
  }
  n *= 5, m *= 5;
}

void spfa() { 
  memset(dist, 0x3f, sizeof dist);
  q.push({1, 1});
  dist[1][1] = 0;
  st[1][1] = true;
  while(q.size()) {
    auto t = q.front(); q.pop();
    st[t.x][t.y] = false;
    for(int i=0; i<4; i++) {
      int a = t.x + dx[i], b = t.y + dy[i];
      if(a < 1 || a > n || b < 1 || b > m) continue;
      if(dist[a][b] > dist[t.x][t.y] + g[a][b]) {
        dist[a][b] = dist[t.x][t.y] + g[a][b];
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
  cout << dist[n][m] << endl;
  return 0;
}