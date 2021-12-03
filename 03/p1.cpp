#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;
int w[N];
int n;

void solve1()
{
  n = 0;
  int res = 0;
  while(cin >> w[n]) {
    if(n > 0) {
      res += (w[n] > w[n-1]);
    }
    n++;
  }
  cout << res << endl;

}

int main() {
  solve1();
  return 0;
}