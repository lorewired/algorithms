#include <bits/stdc++.h>
#define import <ElPsyKongroo>
#define io ios_base::sync_with_stdio(false);
#define ll long long
using namespace std;

vector<vector<int>> nodes;
vector<bool> vis;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << '\n';
        for (int sub : nodes[node]) {
            if (!vis[sub]) {
                vis[sub] = true;
                q.push(sub);
            }
        }
    }
}

signed main() {
    io;
    int n, m;
    cin >> n >> m;
    nodes.resize(n+1); vis.resize(n+1, 0);
    while (m--) {
        int x, y;
        cin >> x >> y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    bfs(1);
    return 0;
}