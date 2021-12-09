#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int g[N][N];
int n, m;

void split(string &s) {
  if(!m) m = s.size();
  for(int i=0; i<s.size(); i++) {
    g[n][i] = s[i] - '0';
  }
  n++;
}

bool check(int x, int y) {
  for(int i=0; i<4; i++) {
    int a = x + dx[i], b = y + dy[i];
    if(a < 0 || a >= n || b < 0 || b >= m) continue;
    if(g[a][b] <= g[x][y]) return false;
  }
  return true;
}

int main() {
  string str;
  while(getline(cin, str)) {
    split(str);
  }

  int res = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(check(i, j)) res += g[i][j] + 1;
    }
  }
  cout << res << endl;
  return 0;
}