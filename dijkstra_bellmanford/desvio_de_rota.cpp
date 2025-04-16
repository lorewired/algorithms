#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf LLONG_MAX
#define V vector
const int mod = 1e9+7;

signed main() {
  int n, m, c, k;
  while(cin >> n >> m >> c >> k && n && m && c && k) {
    auto adj = V<V<pair<int, int>>>(n);
    auto dist = V<int>(n, inf);
    while(m--) {
      int x, y, z;
      cin >> x >> y >> z;
      adj[x].pb({z, y});
      adj[y].pb({z, x});
    }
    set<pair<int, int>> st;
    st.insert({0, k});
    dist[k] = 0;
    while(st.size()) {
      int v = st.begin()->second;
      st.erase(st.begin());
      for(auto [uw, u] : adj[v]) {
        if(v < c-1 && u != v+1) continue;
        if(dist[v]+uw < dist[u]) {
          st.erase({dist[u], u});
          dist[u] = dist[v]+uw;
          st.insert({dist[u], u});
        }
      }
    }
    cout << dist[c-1] << '\n';
  }
  return 0;
}