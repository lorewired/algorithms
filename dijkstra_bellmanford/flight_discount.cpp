#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define inf LLONG_MAX
#define V vector
const int mod = (int)1e9+7;

using namespace std;

V<V<pair<int, int>>> adj;
V<V<int>> dist;

void dij() {
    set<pair<int, int>> st;
    st.insert({0, 1});
    dist[1][0] = dist[1][1] = 0;

    while(st.size()) {
        auto [w, v] = *st.begin();  
        st.erase(st.begin());

        for(auto [uw, uv] : adj[v]) {
            if(dist[v][0]+uw < dist[uv][0]) {
                st.erase({dist[uv][0], uv});
                dist[uv][0] = dist[v][0] + uw;
                st.insert({dist[uv][0], uv});
            }

            if(dist[v][0]+uw/2 < dist[uv][1]) {
                st.erase({dist[uv][1], uv});
                dist[uv][1] = dist[v][0]+uw/2;
                st.insert({dist[uv][1], uv});
            }

            if(dist[v][1]+uw < dist[uv][1]) {
                st.erase({dist[uv][1], uv});
                dist[uv][1] = dist[v][1]+uw;
                st.insert({dist[uv][1], uv});
            }
        }
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    adj =V<V<pair<int, int>>>(n+1);
    dist =V<V<int>>(n+1, V<int>(2, inf));
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].pb({z, y});
    }
    dij();
    cout << min(dist[n][0], dist[n][1]);
    return 0;
}