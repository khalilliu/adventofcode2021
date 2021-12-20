#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;
typedef pair<int, int> PII;
typedef pair<PII, int> PPI;
const int N = 110, M = 30, INF = 1e9;

int DIRS[8][3] = {{1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1},{-1, 1, 1}, {-1, 1, -1}, {-1, -1, 1}, {-1, -1, -1}};
int ROTATIONS[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
int scanp[8][6][N][M][3], sizm[N], pos[N][3];
vector<PPI> g[N];
PII dir[N];
int pts_a[M][3], pts_b[M][3];
bool st[N];
queue<int> good;
vector<int> bad;
map<PPI, int> cnt;
set<PPI> S;
int n = -1;


void print(int pts[M][3], int a) {
  for(int i=0; i<sizm[a]; i++) {
    printf("(%d %d %d) ", pts[i][0], pts[i][1], pts[i][2]);
  }
  cout << endl;
}

// generate all rotations pts for other scanners
void init_scanp() {
  for(int i=0; i<n; i++) {
    sizm[i] = g[i].size();
  }

  for(int i=0; i<sizm[0]; i++) {
    S.insert(g[0][i]);
  }

  for(int d=0; d<8; d++) {
    for(int r=0; r<6; r++) {
      for(int i=0; i<n; i++) {
        for(int j=0; j<sizm[i]; j++) {  
          auto &pt = scanp[d][r][i][j];
          int x = g[i][j].first.first, y = g[i][j].first.second, z = g[i][j].second;
          x *= DIRS[d][0], y *= DIRS[d][1], z *= DIRS[d][2];
          pt[ROTATIONS[r][0]] = x, pt[ROTATIONS[r][1]] = y, pt[ROTATIONS[r][2]] = z;
        }
      }
    }
  }
}

// read input
void init() {
  string s;
  while(getline(cin, s)) {
    if(!s.size()) continue;
    if(s.substr(0, 3) == "---") {
      n++;
    } else if(isdigit(s.back())){
      int x, y, z;
      sscanf(s.c_str(), "%d,%d,%d", &x, &y, &z);
      g[n].push_back({{x,y}, z});
    }
  }
  n++;
}

bool match(int a, int b) {
  cnt.clear();
  for(int i=0; i<sizm[a]; i++) {
    for(int j=0; j<sizm[b]; j++) {
      int dx = pts_a[i][0] + pos[a][0] - pts_b[j][0];
      int dy = pts_a[i][1] + pos[a][1] - pts_b[j][1];
      int dz = pts_a[i][2] + pos[a][2] - pts_b[j][2];
      cnt[{{dx, dy},dz}]++;
    }
  }

  for(auto &c : cnt) {
    PPI t = c.first;
    int val = c.second;
    if(val >= 12) {
      pos[b][0] = t.first.first, pos[b][1] = t.first.second, pos[b][2] = t.second;
      return true;
    }
  }
  return false;
}

bool check(int a, int b) {
  memcpy(pts_a, scanp[dir[a].first][dir[a].second][a], sizeof pts_a);
  
  for(int d=0; d<8; d++){
    for(int r = 0; r<6; r++) {
      memcpy(pts_b, scanp[d][r][b], sizeof pts_b);
      if(match(a, b)) {
        dir[b] = {d, r}; // set right dir for b
        for(int i=0; i<sizm[b]; i++) {
          int dx = pts_b[i][0] + pos[b][0];
          int dy = pts_b[i][1] + pos[b][1];
          int dz = pts_b[i][2] + pos[b][2];
          S.insert({{dx, dy}, dz}); 
        }
        return true;
      } 
    }
  }
  return false;
}

int main() {
  init();
  init_scanp();
  
  good.push(0); dir[0] = {0, 0}, pos[0][0] = 0, pos[0][1] = 0, pos[0][2] = 0;
  for(int i=1; i<n; i++) bad.push_back(i);
  
  int time = 0;
  while(bad.size()) {
    if(time > 50) break;
    auto gd = good.front(); good.pop();
    vector<int> bad_t;
    for(auto bd : bad) {
      if(check(gd, bd)) {
        good.push(bd);
        printf("found: %d, pos: [%d, %d, %d], dir: [%d, %d]\n", bd, pos[bd][0], pos[bd][1], pos[bd][2], dir[bd].first, dir[bd].second);
      } else bad_t.push_back(bd);
    }
    time ++;
    bad = bad_t;
  }

  int ans = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<i; j++) {
      ans = max(ans, abs(pos[i][0] - pos[j][0]) + abs(pos[i][1] - pos[j][1]) + abs(pos[i][2] - pos[j][2]));
    }
  }

  cout << ans << endl;

  return 0;
}



