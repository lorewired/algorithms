#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf LLONG_MAX
#define V vector
const int mod = 1e9+7;

signed main() {
  int n, m, server;
  cin >> n >> m;
  auto adj = V<V<pair<int, int>>>(n+1);
  while(m--) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].pb({z, y});
    adj[y].pb({z, x});
  }
  cin >> server;
  function<int(int, bool)> dij = [&] (int s, bool g) -> int {
    auto dist = V<int>(n+1, inf);
    dist[s] = 0;
    set<pair<int, int>> st;
    st.insert({0, s});
    int dest = g ? 0 : inf;
    while(st.size()) {
      int v = st.begin()->second, w = st.begin()->first;
      st.erase(st.begin());
      if(v != s && g && w > dest) dest = w;
      if(v != s && !g && w < dest) dest = w;
      for(auto it : adj[v]) {
        int u = it.second, uw = it.first;
        if(dist[v]+uw < dist[u]) {
          st.erase({dist[u], u});
          dist[u] = dist[v]+uw;
          st.insert({dist[u], u});
        }
      }
    }
    return dest;
  };
  cout << dij(server, 1) - dij(server, 0);
  return 0;
}