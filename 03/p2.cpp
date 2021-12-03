#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;
int w[N];
int n, res, sum, pre;


int main() {
  n = 0, sum = 0, pre = 0;
  while(cin >> w[n]) {
    pre = sum;
    sum += w[n];
    if(n >= 3) {
      sum -= w[n-3];
      if(sum > pre) res++;
    }
    n++;
  }
  cout << res << endl;
  return 0;
}