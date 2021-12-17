#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int xmin, xmax, ymin, ymax;

int main()
{
    string s; 
    getline(cin, s);
    sscanf(s.c_str(), "target area: x=%d..%d, y=%d..%d", &xmin, &xmax, &ymin, &ymax);
    int h = abs(ymin)*abs(ymin+1)/2;
    cout << h << endl;
    return 0;
}
