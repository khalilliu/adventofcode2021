#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;
int x, y;

int main() {
  string str;
  int a;
  while(cin >> str >> a) {
    if(str == "forward") {
      x += a;
    } else if(str == "up") {
      y -= a;
    } else {
      y += a;
    }
  }
  cout << x * y << endl;
  return 0;
}