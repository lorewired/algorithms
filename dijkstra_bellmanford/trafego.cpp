#include <bits/stdc++.h>
using namespace std;
#define int long long
#define empb emplace_back
#define emp emplace
#define inf LLONG_MAX
#define V vector
const int mod = 1e9+7;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

signed main() {
  int n, m;
  cin >> n >> m;
  V<V<pair<int, int>>> adj(n+1);
  V<int> dist(n+1, inf);
  V<map<int, pair<int, int>>> lights(n+1);
  while(m--) {
    int x, y, z, g, r;
    cin >> x >> y >> z >> g >> r;
    adj[x].empb(z, y);
    lights[x][y] = {g, r};
  }
  set<pair<int, int>> st;
  st.emp(0, 1);
  dist[1] = 0;
  while(st.size()) {
    int v = st.begin()->second;
    st.erase(st.begin());
    for(auto [uw, u] : adj[v]) {
      int cost = dist[v] + uw, g = lights[v][u].first, r = lights[v][u].second;
      int wait = g + r, new_cost;
      if(cost % wait >= g) new_cost = cost + (wait - cost % wait);
      else new_cost = cost;
      if(new_cost < dist[u]) {
        st.erase({dist[u], u});
        dist[u] = new_cost;
        st.emp(dist[u], u);
      }
    }
  }
  cout << dist[n];
  return 0;
}