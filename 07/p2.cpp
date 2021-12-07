#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int w[N];
int n;

void split(string &s) {
  s += ',';
  for(int i=0, j=0; i<s.size(); i++) {
    int t = 0;
    j = i;
    while(j < s.size() && isdigit(s[j])) {
      t = t * 10 + s[j] - '0';
      j++;
    }
    w[n++] = t;
    i = j;
  }
}

void print() {
  for(int i=0; i<n; i++) cout << w[i] << ' ';
  cout << endl;
}

int main() {
  string str;
  getline(cin, str);
  split(str);
  // print();
  int t = 0, res = 0, ans = 0;
  for(int i=0; i<n; i++) t += w[i];
  t /= n;
  for(int i=0; i<n; i++) {
    int a = abs(w[i] - t);
    ans += (a+1)*a/2;
  }
  res = ans, t += 1, ans = 0;
  for(int i=0; i<n; i++) {
    int a = abs(w[i] - t);
    ans += (a+1)*a/2;
  }
  res = min(res, ans);
  cout << res << endl;
  return 0;
}