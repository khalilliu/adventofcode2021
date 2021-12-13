#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
set<PII> pts;
vector<PII> folds;
char g[45][45];

int main() {
  string str;
  while(getline(cin, str)) {
    if(str.size() == 0) break;
    int x, y;
    sscanf(str.c_str(), "%d,%d", &x, &y);
    pts.insert({x, y});
  }
  while(getline(cin, str)) {
    char a;
    int b;
    sscanf(str.c_str(), "fold along %c=%d", &a, &b);
    if(a == 'x') folds.push_back({b, 0});
    if(a == 'y') folds.push_back({0, b});
  }
  
  // cout << pts.size() << endl;
  for(int i=0; i<folds.size(); i++) {
    int x = folds[i].x, y = folds[i].y;
    set<PII> tmp;
    for(auto &p : pts) {
      if(x == 0 && p.y > y) {
        tmp.insert({p.x, y - (p.y - y)});
      }
      if(y == 0 && p.x > x) {
        tmp.insert({x - (p.x - x), p.y});
      } 
      if(x == 0 && p.y < y || y == 0 && p.x < x)
        tmp.insert({p.x, p.y});
    }
    pts = tmp;
  }
  for(int i=0; i<40; i++) {
    for(int j=0; j<40; j++) {
      g[i][j] = ' ';
    }
  }
  for(auto &p : pts) {
    g[p.y][p.x] = '#';
  }

  for(int i=0; i<40; i++) {
    for(int j=0; j<40; j++) {
      cout << g[i][j] ;
    }
    cout << endl;
  }

  return 0;
}