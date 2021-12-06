#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1000010;
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
  string s;
  getline(cin, s);
  split(s);
  print();


  for(int i=0; i<80; i++) {
    int len = n;
    for(int j=0; j<len; j++) {
      w[j] --;
      if(w[j] == -1) {
        w[j] = 6;
        w[n++] = 8;
      }
    }
  }

  cout << n << endl;

  return 0;
}