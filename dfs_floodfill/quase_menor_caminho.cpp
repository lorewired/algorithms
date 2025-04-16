#include <bits/stdc++.h>
using namespace std;
#define int long long
#define empb emplace_back
#define emp emplace
#define inf LLONG_MAX
#define V vector
const int mod = 1e9+7;

signed main() {
  int n, m;
  while(cin >> n >> m && n && m) {
    int s, d;
    cin >> s >> d;
    V<V<pair<int, int>>> adj(n);
    V<int> dist(n, inf), par(n, -1);
    while(m--) {
      int x, y, z;
      cin >> x >> y >> z;
      adj[x].empb(z, y);
    }
    int l = inf;
    map<int, set<int>> paths;
    function<void(bool)> dij = [&] (bool f) {
      dist.assign(n+1, inf);
      dist[s] = 0;
      set<pair<int, int>> st;
      st.emplace(0, s);
      while(st.size()) {
        int v = st.begin()->second;
        st.erase(st.begin());
        for(auto [uw, u] : adj[v]) {
          int cost = dist[v]+uw;
          if(cost <= dist[u]) {
            if(!f && (u == d && cost == l) || paths[l].count(u)) continue;
            if(cost < dist[u]) {
              st.erase({dist[u], u});
              dist[u] = cost;
              st.emp(dist[u], u);
              par[u] = v;
            }
            if(f && u == d) {
              int cur = v;
              while(cur != -1) {
                paths[dist[u]].emp(cur);
                cur = par[cur];
              }
            }
          }
        }
      }
    };
    dij(1);
    l = dist[d];
    dij(0);
    cout << (dist[d] == inf ? -1 : dist[d]) << '\n';
  }
  return 0;
}