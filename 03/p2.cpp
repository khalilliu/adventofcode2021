#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;
string s[N];
int cnt[2][20], tmp[2][20];
bool st[N];
int n, m;

int solve(int u) {
  memcpy(tmp, cnt, sizeof cnt);
  memset(st, 0, sizeof st);
  int tot = n, res = 0, t = 0;
  for(int i=0; i<m; i++) {
    if(u) t = tmp[1][i] >= tmp[0][i] ? 1 : 0;
    else t = tmp[0][i] <= tmp[1][i] ? 0 : 1;
    for(int j=0; j<n; j++) {
      if(s[j][i] - '0' != t && !st[j]) {
        st[j] = true;
        tot--;
        for(int k=i; k<m; k++) {
          tmp[s[j][k] - '0'][k]--;
        }
      }
    }
    if(tot == 1) {
      break;
    }
  }
  for(int i=0; i<n; i++) {
    if(!st[i]) {
      for(int j=0; j<m; j++) {
        res = (res << 1) + (s[i][j] - '0');
      }
      break;
    }
  }
  return res;
}

int main() {
  while(cin >> s[n]) {n++;}
  m = s[0].size();
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++) {
      cnt[s[i][j] - '0'][j]++;
    }
  }
  int a = solve(1), b = solve(0);
  cout << a << ' ' << b << endl;
  cout << a * b << endl;
  return 0;
}