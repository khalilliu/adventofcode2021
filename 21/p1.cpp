#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int T = 1000;
int p1, p2;
int score1, score2;
int step, idx = 1;

int get_step(int t) {
    return t-1 + (t)%100 + (t+1)%100 + 3;
}

int main() {
    string s1, s2;
    getline(cin, s1), getline(cin, s2);
    p1 = s1[s1.size()-1] - '0', p2 = s2[s2.size()-1] - '0';

    p1--, p2--;
    while(score1 < T || score2 < T) {
        p1 = (p1 + get_step(idx)) % 10;
        idx = (idx+3) > 100 ? (idx+3) % 100 : idx+3;
        score1 += p1 + 1;
        step++;
        if(score1 >= T) break;
        p2 = (p2 + get_step(idx)) % 10;
        idx = (idx+3) > 100 ? (idx+3) % 100 : idx+3;
        score2 += p2 + 1;
        step++;
        cout << score1 << ' ' << score2 << endl;
    }
    
    cout << step * 3 * min(score1, score2) << endl;

    return 0;
}
