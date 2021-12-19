#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

const int N = 100010;

int l[N], r[N], p[N], w[N], idx;
bool is_leaf[N], is_left[N];
int h[N], n;

int find(int root, int depth) {
    if(root == -1) return root;
    if(depth == 0) {
        if(!is_leaf[root]) return root;
        else return -1;
    }
    int node = find(l[root], depth-1);
    if(node != -1) return node;
    return find(r[root], depth-1);
}

void add_left(int node, int val) {
    if(!is_left[node]) {
        int p_node = p[node];
        if(is_leaf[l[p_node]]) w[l[p_node]] += val;
        else {
            int p_right = r[l[p_node]];
            while(!is_leaf[p_right]) p_right = r[p_right];
            w[p_right] += val;
        }
    } else {
        int p_node = p[node];
        while(p_node != -1 && is_left[p_node]) p_node = p[p_node];
        if(p_node == -1 || p[p_node] == -1) return;
        add_left(p_node, val);
    }
}

void add_right(int node, int val) {
    if(is_left[node]) {
        int p_node = p[node];
        if(is_leaf[r[p_node]]) w[r[p_node]] += val;
        else {
            int p_left = l[r[p_node]];
            while(!is_leaf[p_left]) p_left = l[p_left];
            w[p_left] += val;
        }
    } else {
        int p_node = p[node];
        while(p_node != -1 && !is_left[p_node]) p_node = p[p_node];
        if(p_node == -1 || p[p_node] == -1) return;
        add_right(p_node, val);
    }
}

bool explode(int root) {
    int node = find(root, 4);
    if(node == -1) return false;
    add_left(node, w[l[node]]), add_right(node, w[r[node]]);
    l[node] = r[node] = -1;
    w[node] = 0, is_leaf[node] = true;
    return true;
}

bool split(int root) {
    if(is_leaf[root]) {
        if(w[root] >= 10) {
            w[++idx] = w[root] / 2, l[root] = idx, p[idx] = root, is_leaf[idx] = true, is_left[idx] = true;
            w[++idx] = (w[root] + 1)/2, r[root] = idx, p[idx] = root, is_leaf[idx] = true, is_left[idx] = false;
            w[root] = 0, is_leaf[root] = false;
            return true;
        } 
        return false;
    }
    auto has_changed = split(l[root]);
    if(has_changed) return true;
    has_changed = split(r[root]);
    return has_changed;
}

void do_clear(int root) {
    while(true) {
        bool has_changed = explode(root);
        if(has_changed) continue;
        has_changed = split(root);
        if(!has_changed) break;
    }
}

int add(int a, int b) {
    idx++;
    l[idx] = a, r[idx] = b, p[a] = idx, p[b] = idx;
    is_left[a] = true, is_left[b] = false;
    int root = idx;
    do_clear(root);
    return root;
}

int magnitude(int root) {
    if(is_leaf[root]) return w[root];
    return 3 * magnitude(l[root]) + 2 * magnitude(r[root]);
}

void init(){
    idx = -1;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    memset(p, -1, sizeof p);
    memset(w, 0, sizeof w);
    memset(is_leaf, 0, sizeof is_leaf);
    memset(is_left, 0, sizeof is_left);
}

int parse(string &s) {
    stack<int> stk;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ']') {
            auto b = stk.top(); stk.pop();
            auto a = stk.top(); stk.pop();
            idx++;
            l[idx] = a, r[idx] = b, p[a] = idx, p[b] = idx;
            is_left[a] = true;
            stk.push(idx);
        } else if(s[i] >= '0' && s[i] <= '9') {
            w[++idx] = s[i] - '0', is_leaf[idx] = true;
            stk.push(idx);
        }
    }
    return stk.top();
}

string stringify(int root) {
    if(is_leaf[root]) {
        return to_string(w[root]);
    } 
    return '[' +  stringify(l[root]) + ',' + stringify(r[root]) + ']';
}

int main() {
    init();
    string s;
    while(getline(cin, s)) {
        h[n++] = parse(s);
    }
    int root = h[0];
    for(int i=1; i<n; i++) {
       root = add(root, h[i]);
    }
    int res = magnitude(root);
    cout << res << endl;
    return 0;
}
