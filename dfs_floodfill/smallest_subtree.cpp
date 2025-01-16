#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

map<int, vector<int>, greater<int>> mp;
vector<vector<int>> adj;
vector<int> vis;

void dfs(int p, int v, int c) {
    vis[v]=1;
    int l=1;
    for (int u : adj[v]) {
        if (!vis[u]) {
            l=0;
            dfs(v, u, c+1);
        }
    }
    if (l) {
        vector<int> subt={p};
        subt.push_back(adj[p][0]);
        subt.push_back(adj[p][1]);
        mp[c]=subt;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n, root;
    cin>>n>>root;
    adj.resize(n);
    vis.resize(n, 0);
    for (int i=1; i<n; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vis[root]=1;
    for (int u : adj[root])
        dfs(root, u, 1);
    vector<int> ans = {root};
    if (mp.size()) {
        ans.clear();
        ans = mp.begin()->second;
    }
    cout<<'[';
    for (int i=0; i<ans.size(); i++)
       cout<<(!i?"":", ")<<ans[i];
    cout<<']';
    return 0;
}