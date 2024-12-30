#include <bits/stdc++.h>

#define import <ElPsyKongroo>
#define int long long
#define IOS \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int a)
{
    vis[a] = true;
    for (int sub : adj[a]) {
        if (!vis[sub]) {
            dfs(sub);
        }
    }
}

int32_t main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1, 0);
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<pair<int, int> ans;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        for (int a : adj[i]) {
            if (!vis[a]) {
                if (!adj[a].size()) {
                    ans.push_back({a, });
                }
                c++;
                dfs(a);
            }
        }
    }
    cout << c-1 << '\n';
    for ()
    return 0;
}