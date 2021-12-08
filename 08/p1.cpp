#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 210, M = 14;
int w[N][M];
int n;

int lowbit(int x) {
  return x & -x;
}

int ones(int x) {
  int ans = 0;
  while(x) {
    x -= lowbit(x);
    ans ++;
  }
  return ans;
}

void split(string &s) {
  int m = s.size(), l = 0;
  for(int i=0, j=0; i<m; i++) {
    if(s[i] == '|') { i++; continue;}
    j = i;
    int a = 0;
    while(j < m && s[j] != ' ') {
      a |= 1 << (s[j] - 'a');
      j++;
    }
    // cout << s.substr(i, j-i) << ' ';
    w[n][l++] = a, i = j;
  }
  // cout << endl;
  n++;
}

int main() {
  string str;
  while(getline(cin, str)) {
    split(str);
  }

  int ans = 0;
  for(int i=0; i<n; i++) {
    int a1, a4, a7, a8;
    for(int j=0; j<10; j++) {
      if(ones(w[i][j]) == 2) a1 = w[i][j];
      else if(ones(w[i][j]) == 3) a7 = w[i][j];
      else if(ones(w[i][j]) == 7)  a8 = w[i][j];
    }
    for(int j=0; j<10; j++) {
      if(ones(w[i][j]^a1) == 2) a4 = w[i][j];
    }
    cout << "a1:" << a1 << " a4:" << a4 << " a7:" << a7 << " a8:" << a8 << endl;
    for(int j=10; j<14; j++) {
      cout << w[i][j] << ' ';
      if(w[i][j] == a1 || w[i][j] == a4 || w[i][j] == a7 || w[i][j] == a8) {
        // cout << w[i][j] << ' ';
        ans++;
      }
    }
    cout << endl;
  }

  cout << ans << endl;
  return 0;
}