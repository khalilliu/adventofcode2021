#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 110;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int g[N][N];
bool st[N][N];
vector<int> s;
int n, m;

void split(string &s) {
  if(!m) m = s.size();
  for(int i=0; i<s.size(); i++) {
    g[n][i] = s[i] - '0';
  }
  n++;
}

void dfs(int x, int y, int &t) {
  st[x][y] = true;
  t ++;
  for(int i=0; i<4; i++) {
    int a = x + dx[i], b = y + dy[i];
    if(a < 0 || a >= n || b < 0 || b >=m || g[a][b] == 9 || st[a][b]) continue;
    dfs(a, b, t);
  }
}


int main() {
  string str;
  while(getline(cin, str)) {
    split(str);
  }

  int res = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(!st[i][j] && g[i][j] < 9) {
        int t = 0; 
        dfs(i, j, t);
        s.push_back(t);
      }
    }
  }

  sort(s.begin(), s.end(), greater<int>());
  cout << s[0] * s[1] * s[2] << endl;
  return 0;
}