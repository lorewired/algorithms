#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

map<char, vector<char>> adj;
set<char> used;

void dfs(char v) {
    used.insert(v);
    for (char u : adj[v])
        if (!used.count(u))
            dfs(u);
}

void solve() {
    char last; cin>>last; cin.ignore();
    string l;
    for (char i='A'; i<=last; i++) adj[i]={};
    while (getline(cin,l) && !l.empty()) {
        adj[l[0]].push_back(l[1]);
        adj[l[1]].push_back(l[0]);
    }
    int c=0;
    for (auto p:adj) {
        if (!used.count(p.first)) {
            c++;
            dfs(p.first);
        }
    }
    cout<<c<<'\n';
    adj.clear(); used.clear();
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt; cin.ignore(); cin.ignore();
    while (tt--) {
        solve();
        if (tt) cout<<'\n';
    }
    return 0;
}