#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

const int N = 110, M = (1<<5) - 1;

unordered_map<int, vector<PII>> mp;
int row[N][5], col[N][5], g[N][5][5], tmp[N][5];
int nums[N*2];
int n, m, a, b, ans, flag;

void split(string& str, char delimiter) {
  str += delimiter;
  for(int i=0; i<str.size(); i++) {
    int j = i, t = 0;
    while(j < str.size() && str[j] != delimiter) {
      t = t * 10 + (str[j++] - '0');
    }
    nums[n++] = t, i = j;
  }
}

int main() {
  string str;
  getline(cin, str);
  split(str, ',');
  while(getline(cin, str)) {
    for(int i=0; i<5; i++) {
      for(int j=0; j<5; j++) {
        int x; cin >> x;
        cout << x << endl;
        g[m][i][j] = x;
        mp[x].push_back({m, i*5 + j});
      }
    }
    getchar();
    m++;
  }

  for(int i=0; i<n; i++) {
    int t = nums[i];
    for(auto &v : mp[t]) {
      int j = v.first, x = v.second/5, y = v.second%5;
      col[j][x] |= (1<<y), row[j][y] |= (1<<x);
      if(col[j][x] == M) {
        ans = j, a = t, flag = 1;
        break;
      }
      if(row[j][y] == M) {
        ans = j, a = t, flag = 1;
        break;
      }
    } 
    if(flag) break;
  }

  cout << ans << ' ' << a << endl;

  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      if(col[ans][i] >> j & 1) continue;
      b += g[ans][i][j];
    }
  }

  cout << a * b << endl;

  return 0;
}