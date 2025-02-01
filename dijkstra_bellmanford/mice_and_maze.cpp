#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF LLONG_MAX
#define pb push_back
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

vvpi adj;
vi dist;
int ans = 0;

void dijkstra(int src, int dest, int t) {
  set<pi> st;
  st.insert({0, src});
  dist[src] = 0;

  while(st.size()) {
    auto [d, v] = *st.begin();
    st.erase({d, v});

    if(v == dest && d <= t) ans++;

    for(auto [cost, u] : adj[v]) {
      if(dist[v] + cost < dist[u]) {
        st.erase({dist[u], u});
        dist[u] = dist[v] + cost;
        st.insert({dist[u], u});
      }
    }
  }
}

void solve() {

  int n, dest, t, m;
  cin >> n >> dest >> t >> m;
  adj = vvpi(n+1);
  ans = 0;
  
  while(m--) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].pb({z, y});
  }

  for(int i = 1; i <= n; i++) {
    dist.assign(n+1, INF);
    dijkstra(i, dest, t);
  }

  cout << ans << '\n';
}


signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int tt; cin >> tt;
  int f = 1;
  while (tt--) {
    if(!f) cout << '\n';
    f = 0;
    solve();
  }
  return 0;
}