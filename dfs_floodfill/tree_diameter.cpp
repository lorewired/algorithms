#include <bits/stdc++.h>
#define import <ElPsyKongroo>
#define io ios_base::sync_with_stdio(false);
#define ll long long
using namespace std;

vector<vector<int>> adj;
vector<int> len, vis;
int bg = 0, gc = 0;

void dfs(int v, int c) {
    if (c > gc) {
        gc = c;
        bg = v;
    }
    vis[v] = 1;
    len[v] = c++;
    for (int sub : adj[v])
        if (!vis[sub])
            dfs(sub, c);
}

signed main() {
    io;
    int n;
    cin >> n;
    adj.resize(n+1); vis.resize(n+1, 0); len.resize(n+1);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0); // buscar a maior folha
    vis.assign(n+1, 0); len.assign(n+1, 0);
    gc = 0; // maior aresta
    dfs(bg, 0); // buscar a maior folha a partir da maior atual
    cout << gc << '\n';
    return 0;
}