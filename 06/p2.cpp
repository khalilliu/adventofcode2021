#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 10;
LL w[N], tmp[N];
LL n;

void split(string &s) {
  s += ',';
  for(int i=0, j=0; i<s.size(); i++) {
    int t = 0;
    j = i;
    while(j < s.size() && isdigit(s[j])) {
      t = t * 10 + s[j] - '0';
      j++;
    }
    w[t]++;
    n++;
    i = j;
  }
}

void print() {
  for(int i=0; i<=8; i++) {
    cout << w[i] << ' ';
  }
  cout << endl;
}


int main() {
  string s;
  getline(cin, s);
  split(s);
  print();


  for(int i=0; i<256; i++) {
    memset(tmp, 0, sizeof tmp);
    n += w[0];
    for(int j=0; j<8; j++) {
      tmp[j] = w[j+1];
    }
    tmp[8] = w[0], tmp[6] += w[0];
    memcpy(w, tmp, sizeof w);
  }

  cout << n << endl;

  return 0;
}