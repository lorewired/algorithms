#include <bits/stdc++.h>
#define import <ElPsyKongroo>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
int valid=1;

void is_cyclic(int v) {
    if (adj[v].size()!=2) valid=0;
    vis[v]=1;
    for (int u:adj[v])
        if (!vis[u])
            is_cyclic(u);
}

signed main() {
    io;
    int n, m, t=0;
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1,0);
    while (m--) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            valid=1;
            is_cyclic(i);
            if (valid) t++;
        }
    }
    cout<<t<<'\n';
    return 0;
}