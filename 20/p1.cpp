#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 100, INF = 1e9;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
set<PII> lights, temp;
string algo;

int get(int x, int y, bool on) {
  int res = 0;
  for(int dx=-1; dx<=1; dx++) {
    for(int dy=-1; dy<=1; dy++) {
      int a = x + dx, b = y + dy;
      if((bool)lights.count({a, b}) == on) res = (res << 1) + 1;
      else res = (res << 1) + 0;
    }
  }
  return res;
}

void iterate(bool on) {
  temp.clear();
  for(auto &l : lights) {
    xmin = min(xmin, l.first);
    xmax = max(xmin, l.first);
    ymin = min(xmin, l.second);
    ymax = max(xmin, l.second);
  }
  for(int i=xmin-5; i<=xmax+10; i++) {
    for(int j=ymin-5; j<=ymax+10; j++) {
      if((algo[get(i, j, on)] == '#') != on) {
        temp.insert({i, j});
      }
    }
  }
  lights = temp;
  cout << "iterator" << endl;
}

int main() {
  getline(cin, algo);
  string s;
  int n = 0;
  getline(cin, s);
  while(getline(cin, s)) {
    for(int i=0; i<s.size(); i++) {
      if(s[i]=='#') {
        lights.insert({n, i});
      }
    }
    xmin = 0, xmax = max(xmax, n), ymin = 0, ymax = max(ymax, (int)s.size()-1);
    n++;
  }

  cout << algo.size() << endl;
  for(int i=0; i<50; i++) {
    cout << i << endl;
    iterate(i%2 == 0);
  }

  cout << lights.size() << endl;
  return 0; 
}