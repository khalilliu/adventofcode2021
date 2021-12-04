#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;
string s[N];
int n;

int main() {
  while(cin >> s[n]) {n++;}
  int m = s[0].size();
  int a = 0, b = 0;
  // for(int i=0; i<n; i++) cout << s[i] << endl;
  for(int i=0; i<m; i++) {
    int t0 = 0, t1 = 0;
    for(int j=0; j<n; j++) {
      int t = s[j][i] - '0';
      if(t == 1) t1++;
      else t0++;
    }
    a = (a << 1) + (t1 > t0);
    b = (b << 1) + (t1 < t0);
  }
  cout << a * b << endl;
  return 0;
}