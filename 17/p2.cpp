#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int xmin, xmax, ymin, ymax;
int ans;

bool check(int vx, int vy) {
    int x = 0, y = 0;
    while(true) {
        x += vx, vx = max(vx-1, 0);
        y += vy, vy -= 1;
        if(x >= xmin && x <= xmax && y >= ymin && y <= ymax) return true;
        if(x > xmax) break;
        if(y < ymin) break;
        if(x == 0 && (x < xmin || x > xmax)) break;

    }
    return false;
}

int main()
{
    string s; 
    getline(cin, s);
    sscanf(s.c_str(), "target area: x=%d..%d, y=%d..%d", &xmin, &xmax, &ymin, &ymax);
 
    for(int i=1; i<=xmax; i++) {
        for(int j=ymin; j<abs(ymin); j++) {
            if(check(i, j)) ans++;
        }
    }
    cout << ans  << endl;
    return 0;
}
