#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

vector<vector<pair<int, int>>> adj(100010);
vector<int> dist(100010, LLONG_MAX);

void dijkstra(int n) {
    dist[1] = 0;
    set<pair<int, int>> st;
    st.insert({0, 1});
    vector<int> par(n+1, -1);

    while(st.size()) {
        int cur = st.begin()->second;
        st.erase(st.begin());
        
        for(auto u : adj[cur]) {
            int uw = u.first;
            int uv = u.second;
            if(dist[cur]+uw < dist[uv]) {
                st.erase({dist[uv], uv});
                dist[uv] = dist[cur]+uw;
                st.insert({dist[uv], uv});
                par[uv] = cur;
            }
        }
    }

    if(dist[n] == LLONG_MAX) {
        cout << -1 << '\n';
    } else {
        vector<int> ans;
        int cur = n;
        while(cur != -1) {
            ans.push_back(cur);
            cur = par[cur];
        }
        for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << ' ';
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({w, y});
        adj[y].push_back({w, x});
    }
    dijkstra(n);
    return 0;
}