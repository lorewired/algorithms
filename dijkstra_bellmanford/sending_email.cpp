#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

#define int long long
#define inf LLONG_MAX

int dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& dist, int s, int t) {
    set<pair<int, int>> st;
    st.insert({0, s});  
    dist[s] = 0;

    while(st.size()) {
        int u = st.begin()->second;
        st.erase(st.begin());

        for(auto i : adj[u]) {
            int v = i.first, w = i.second;
            if(dist[u]+w < dist[v]) {
                st.erase({dist[v], v});
                dist[v] = dist[u]+w;
                st.insert({dist[v], v});
            }
        }
    }

    return dist[t];
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt, c = 1; cin >> tt;
    while(tt--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, inf);
        while(m--) {
            int x, y, w;
            cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        int ans = dijkstra(adj, dist, s, t);
        cout << "Case #" << c++ << ": ";
        cout << (ans == inf ? "unreachable" : to_string(ans)) << '\n';
    }
    return 0;
}