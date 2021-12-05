#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
typedef pair<int, int> PII;

const int N = 1010;
int sum[N][N];
unordered_map<int, vector<PII>>mpx, mpy;
vector<vector<PII>> mpz;

void calc(unordered_map<int, vector<PII>> &mp, int flag) {
  for(auto &arr : mp) {
    int t = arr.first;
    for(auto &v : arr.second) {
      int a = v.first, b = v.second;
      if(a > b) swap(a, b);
      // cout << v.first << ' ' << v.second << endl;
      for(int i=a; i<=b; i++) {
        if(flag == 0) sum[t][i]++;
        else sum[i][t]++;
      }
    }
  }
}


int main() {
  string str;
  while(getline(cin, str)) {
    int x1, y1, x2, y2;
    sscanf(str.c_str(), "%d,%d -> %d,%d\n", &x1, &y1, &x2, &y2);
    x1++, y1++, x2++, y2++;
    // cout << x1 << y1 << x2 << y2 << endl;
    if(x1 == x2) mpx[x1].push_back({y1, y2});
    else if(y1 == y2) mpy[y1].push_back({x1, x2});
  }
  calc(mpx, 0), calc(mpy, 1);
  int res = 0;
  for(int i=1; i<N; i++) {
    for(int j=1; j<N; j++) {
      // cout << sum[i][j] << ' ';
      res += (sum[i][j] >= 2);
    }
    // cout << endl;
  }
  cout << res << endl;
  return 0;
}