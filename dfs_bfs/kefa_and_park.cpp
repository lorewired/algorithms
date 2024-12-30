#include <bits/stdc++.h>

#define import <ElPsyKongroo>
#define int long long
#define IOS \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)

using namespace std;

vector<vector<int>> nodes;
vector<int> vis, cat;
int n, m, ans = 0;

void search (int v, int c) {
    vis[v] = 1;

    if (cat[v]) c++;
    else c = 0;

    if (c > m) return;

    bool leaf = true;
    for (int sub : nodes[v]) {
        if (!vis[sub]) {
            leaf = false;
            search(sub, c);
        }
    }

    if (leaf) ans++;
}

int32_t main()
{
    IOS;
    cin >> n >> m;
    nodes.resize(n+1); vis.resize(n+1); cat.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x].push_back(y);
        nodes[y].push_back(x);
    }
    search(1, 0);
    cout << ans << '\n';
    return 0;
}