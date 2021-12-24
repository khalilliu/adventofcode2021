#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;
typedef pair<int, int> PII;
typedef pair<int, pair<int, int>> PPI;
struct State {
    int cost;
    vector<PPI> pods;
    State(int _cost, vector<PPI> _pods) : cost(_cost), pods(_pods) {};
    bool operator < (const State &st) const {cost < st.cost};
    bool operator > (const State &st) const {cost > st.cost};
};

string grid[5] = {
"#############", 
"#...........#", 
"###.#.#.#.###",
"  #.#.#.#.#",
"  #########"};
priority_queue<State, vector<State>, greater<State>> heap;
string hallway, row_1, row_2;
vector<PPI> start_pods(8), end_pods(8), cur_pods(8);
int type_counter[4];
map<vector<PPI>, int> cost;
map<vector<PPI>, vector<PPI>> edges;
set<vector<PPI>> visited;
State start_st;
int ans;


vector<State> extends(State &st) {
    int cur_cost = st.cost;
    auto cur_pods = st.pods;

    for()
}

bool check_ends(vector<PPI>& pods) {
    for(int i=0; i<pods.size(); i++) {
        auto t = pods[i];
        if(t.first != -1) return false;
        if(t.second.first != i/2*2 + 2) return false;
    }
    return true;
}

void read_input() {
    vector<string> raw_data;
    string s;
    while(getline(cin, s)) {
        raw_data.push_back(s);
    }
    hallway = raw_data[1].substr(1, 11);
    row_1 = raw_data[2][3] + raw_data[2][5] + raw_data[2][7] + raw_data[2][9];
    row_2 = raw_data[3][3] + raw_data[3][5] + raw_data[3][7] + raw_data[3][9];
}

void parse_input() {
    for(auto &c : hallway) {
        if(c == '.') continue;
        int t = c - 'A';   
        start_apods[t*2 + type_counter[t]] = {t, {-1, -1}};
        type_counter[t] ++;
    }
    // pods{0 -> A, 1 -> A, 2 -> B, 3 -> B}
    for(int i=0; i<4; i++) { //  2  4  6  8
        if(row_1[i] == '.') continue;
        int t = row_1[i] - 'A'; //
        start_apods[t*2 + type_counter[t]] = {-1, {i*2+2, 1}};
        type_counter[t] ++;
    }
    for(int i=0; i<4; i++) {
        if(row_2[i] == '.') continue;
        int t = row_2[i] - 'A';
        start_apods[t*2 + type_counter[t]] = {-1, {i*2+2, 2}};
        type_counter[t] ++;
    }
}

void print_pods(vector<PPI>& pods) {

}

int main() {
    read_input();
    parse_input();

    start_st = {0, start_apods};

    heap.push(start_st);
    while(heap.size()) {
        auto t = heap.top(); heap.pop();
        if(visited.count(t.pods)) continue;
        visited.insert(t.pods);
        cost[t.pods] = t.cost;
        if(check_ends(t.pods)) {
            ans = t.cost;
            end_pods = t.pods;
            break;
        }

        for(auto &st : extends(t)) {
            if(visited.count(st.pods)) continue;
            edges[st.pods] = t.pods;
            heap.push(st);
        }
    }

    cur_pods = end_pods;

    while(edges.count(cur_pods)) {
        cout <<  cost[cur_pods] << endl;
        print_pods(cur_pods);
        cur_pods = edges[cur_pods];
    }
    cout << ans << endl;
    return 0;
}



