#include <bits/stdc++.h>
#define import <ElPsyKongroo>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
using namespace std;

using pi = pair<int,int>;
vector<vector<int>> adjs;
map<int, int> edges;
vector<bool> vis;

pi dfs(int v, pi p) {
    vis[v] = true;
    p.first++;
    if (edges.count(v))
        p.second += edges[v];
    for (int conn : adjs[v])
        if (!vis[conn])
            p = dfs(conn, p);
    return p;
}

signed main() {
    io;
    int n, m;
    cin >> n >> m;
    adjs.resize(n+1);
    vis.resize(n+1, 0);
    bool valid = false;
    for (int i= 1; i <= m; i++) {
        valid = true;
        int x, y;
        cin >> x >> y;
        adjs[x].push_back(y);
        adjs[y].push_back(x);
        edges[x]++;
    }
    for (int i = 1; i <= n && valid; i++) {
        if (!vis[i]) {
            pi p = dfs(i, {0,0});
            if (p.second && p.first != p.second) {
                valid = false;
            }
        }
    }
    cout << (valid ? "Yes\n" : "No\n");
    return 0;
}