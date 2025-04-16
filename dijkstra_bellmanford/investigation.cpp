#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf LLONG_MAX
#define V vector
const int mod = 1e9+7;
 
signed main() {
  int n, m;
  cin >> n >> m;
  auto adj = V<V<pair<int, int>>>(n+1);
  V<int> dist(n+1, inf), min_r(n+1, inf), max_r(n+1), count(n+1);
  while(m--) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].pb({z, y});
  }
  set<pair<int, int>> st;
  st.insert({0, 1});
  count[1] = 1;
  max_r[1] = min_r[1] = dist[1] = 0;
  while(st.size()) {
    int v = st.begin()->second;
    st.erase(st.begin());
    for(auto [uw, u] : adj[v]) {
      int cost = dist[v]+uw;
      if(cost < dist[u]) {
        st.erase({dist[u], u});
        dist[u] = cost;
        st.insert({dist[u], u});
        count[u] = count[v];
        min_r[u] = min_r[v] + 1;
        max_r[u] = max_r[v] + 1;
      }
      else if(cost == dist[u]) {
        count[u] = (count[u] + count[v]) % mod;
        min_r[u] = min(min_r[u], min_r[v] + 1);
        max_r[u] = max(max_r[u], max_r[v] + 1);
      }
    }
  }
  cout << dist[n] << ' ' << count[n] << ' ' << min_r[n] << ' ' << max_r[n];
  return 0;
}
