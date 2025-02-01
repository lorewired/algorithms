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

using tiii = tuple<int, int, int>;
vvpi adj;
int n, m;

int dij() {
  vvi dist(n, vi(2, INF));
  priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

  dist[1][0] = 0;
  pq.push({0, 1, 0});

  while(pq.size()) {
    auto [cost, v, used] = pq.top();
    pq.pop();

    if(cost > dist[v][used]) continue;

    for(auto [u, w] : adj[v]) {
      if(dist[u][used] > cost + w) {
        dist[u][used] = cost + w;
        pq.push({dist[u][used], u, used});
      }

      if(!used && dist[u][1] > (cost + w) / 2) {
        dist[u][1] = (cost + w) / 2;
        pq.push({dist[u][1], u, 1});
      }
    }
  }

  return min(dist[n][0], dist[n][1]);
}


signed main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  cin >> n >> m;
  adj = vvpi(n);
  while(m--) {
    int x, y, p;
    cin >> x >> y >> p;
    x--; y--;
    adj[x].pb({y, p});
  }
  cout << dij() << '\n';
  return 0;
}