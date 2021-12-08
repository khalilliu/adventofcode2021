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
    int a[10];
    for(int j=0; j<10; j++) {
      if(ones(w[i][j]) == 2) a[1] = w[i][j];
      else if(ones(w[i][j]) == 3) a[7] = w[i][j];
      else if(ones(w[i][j]) == 7)  a[8] = w[i][j];
    }
    for(int j=0; j<10; j++) {
      int t = w[i][j];
      if(ones(t^a[1]) == 2) a[4] = t;
    }
    for(int j=0; j<10; j++) {
      int t = w[i][j];
      if(ones(t) == 6) {
        if(ones(t&a[1]) == 1) a[6] = t;
        else if(ones(t&a[4]) == 3) a[0] = t;
        else if(ones(t&a[4]) == 4) a[9] = t;
      } 
      if(ones(t) == 5) {
        if(ones(t&a[1]) == 2) a[3] = t;
        else if(ones(t&a[4]) == 3) a[5] = t;
        else if(ones(t&a[4]) == 2) a[2] = t;
      }
    }
    for(int j=0; j<10; j++) cout << a[j] << ' ';
    cout << endl; 
    int t = 0;
    for(int j=10; j<14; j++) {
      int k;
      for(k=0; k<10; k++) {
        if(a[k] == w[i][j]) break;
      }
      t = t * 10 + k;
    }
    ans += t;
    cout << t << endl;
  }

  cout << ans << endl;
  return 0;
}