#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct PII {
    PII *left, *right, *parent;
    int val, depth;
    bool is_leaf;
};

vector<PII> ps;

// bool explode(PII &p) {
//     auto root = p;

// }

// bool split(PII &p) {
//     if(p->is_leaf) {
//         if(p->val >= 10) {
//             p->left = PII{null, null, p, p->val/2, p->depth+1, true};
//             p->right = PII{null, null, p, (p->val+1)/2, p->depth+1, true};
//             return true;
//         }
//         return false;
//     }
    
//     auto hasChange = split(p->left);
//     if(hasChange) {
//         return true;
//     }
//     hasChange = split(p->right);
//     return hasChange;
// }

// void addup(PII &p){
//     while(true){
//         auto hasChange = explode(p);
//         if(hasChange) continue;
//         hasChange = split(p);
//         if(!hasChange) break;
//     }
// }

// PII add(PII &a, PII &b) {
//     PII ans;
//     ans->left = *a, a->right = *b;
//     a->parent = *ans, b->parent = *ans;
//     a->depth += 1, b->depth += 1;
//     ans->depth = 0;
//     // clear the ans
//     addup(ans);
//     return ans;
// }

// int magnitude(PII &root) {
//     if(root->is_leaf) {
//         return root->val;
//     }
//     return 3 * magnitude(root->left) + 2 * magnitude(root->right);
// }


PII parse(string &s) {
    stack<PII> stk;
    int depth = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == ']') {
            PII cur; 
            cout << stk.size() << endl;
            auto r = stk.top(); stk.pop();
            auto l = stk.top(); stk.pop();
            *cur.left = l, *cur.right = r, cur.is_leaf = false;
            *l.parent = cur, *r.parent = cur;
            cur.depth = l.depth-1;
            depth--;
            stk.push(cur);
        } else if(s[i] == '[') {depth++;}
        else if(s[i] >= '0' && s[i] <= '9') {
            PII cur = {nullptr, nullptr, nullptr, s[i] - '0', depth, true};
            stk.push(cur);
        }
    }
    return stk.top();
}

int main() {
    string s;
    while(getline(cin, s)) {
        auto t = parse(s);
        ps.push_back(t);
    }
    cout << "done" << endl;
    // cout << ps[0].val << endl;
//    PII ans = ps[0];
//    for(int i=1; i<ps.size(); i++) {
//        ans = add(ans, ps[i]);
//   }
//   cout << magnitude(ans) << endl;
    return 0;
}
