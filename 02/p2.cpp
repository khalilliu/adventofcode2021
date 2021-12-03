#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
LL x, y, z;

int main() {
  string str;
  int a;
  while(cin >> str >> a) {
    if(str == "forward") {
      x += a;
      y += z * a;
    } else if(str == "down") {
      z += a;
    } else {
      z -= a;
    }
  }
  cout << (LL)x * y << endl;
  return 0;
}