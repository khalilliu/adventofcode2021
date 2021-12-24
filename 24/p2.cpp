#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int>PII;
vector<vector<string>> monad(14);
int max_v[14], min_v[14];
stack<PII> stk;

string T1 = "div z 1";
string T2 = "div z 26";

void read_input()
{
  int n = -1;
  string s;
  while (getline(cin, s))
  {
    if (s[0] == 'i')
    {
      n++;
    }
    monad[n].push_back(s);
  }
}


int main() {
    read_input();
    for(int i=0; i<14; i++) {
        if(monad[i][4] == T1) {
            int t;
            sscanf(monad[i][15].c_str(), "add y %d", &t);
            stk.push({i, t});
        } else if (monad[i][4] == T2){
            auto t = stk.top(); stk.pop();
            int b = t.first, a = i;
            int x;
            sscanf(monad[i][5].c_str(), "add x %d", &x);
            int diff = x + t.second;
            if(diff < 0) {
                swap(a, b); diff = -diff;
            }
            max_v[a] = 9, max_v[b] = 9 - diff, min_v[a] = 1 + diff, min_v[b] = 1;
        }
    }
    long long ans = 0;
    for(int i=0; i<14; i++) {
        ans = ans * 10 + min_v[i];
    }
    cout << ans << endl;
    return 0;
}
