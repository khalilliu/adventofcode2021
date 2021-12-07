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
  sort(w, w+n);
  print();
  int t = w[n/2], res = 0;
  for(int i=0; i<n; i++) {
    res += abs(t - w[i]);
  }
  cout << res << endl;
  return 0;
}