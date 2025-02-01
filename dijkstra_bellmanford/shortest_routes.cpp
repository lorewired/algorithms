#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> dist(n, LONG_LONG_MAX);
    while(m--) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x-1].push_back({y-1, w});
    }
    dist[0] = 0;
    set<pair<int, int>> st;
    st.insert({0, 0});
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
    for(int i : dist) cout << i << ' ';
    return 0;
}