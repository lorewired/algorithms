#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define inf LLONG_MAX
#define V vector
const int mod = (int)1e9+7;

using namespace std;

V<V<pair<int, int>>> adj;
V<int> dist;

void dij(int s) {
  set<pair<int, int>> st;
  st.insert({0, s});
  dist[s] = 0;

  while(st.size()) {
    auto [w, cur] = *st.begin();
    st.erase(st.begin());

    for(auto [uw, u] : adj[cur]) {
      if(dist[cur]+uw < dist[u]) {
        st.erase({dist[u], u});
        dist[u] = dist[cur]+uw;
        st.insert({dist[u], u});
      }
    }
  }
}

signed main() {
  int n, m;
  cin >> n >> m;
  adj = V<V<pair<int, int>>>(n+1);
  dist = V<int>(n+1, inf);
  while(m--) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].pb({z, y});
  }
  dij(1);
  for(int i=1;i<=n;i++) cout << dist[i] << ' ';
  return 0;
}