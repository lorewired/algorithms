#include <bits/stdc++.h>

#define V vector
#define int long long
#define _ cin.tie(0)->sync_with_stdio(0);

using namespace std;
const int MOD = 1e9+7;
const int oo = 0x3f3f3f3f;

signed main() { _
  int N, M; cin >> N >> M;
  V<V<pair<int, int>>> graph(N);
  while(M--) {
    int x, y, z; cin >> x >> y >> z, x--, y--;
    graph[x].emplace_back(z, y);
    graph[y].emplace_back(z, x);
  }
  function<V<int>(int)> f = [&] (int s) -> V<int> {
    priority_queue<pair<int, int>, V<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);
    V<int> dist(N, oo);
    dist[s] = 0;
    while(pq.size()) {
      auto [w, v] = pq.top(); pq.pop();
      if(w > dist[v]) continue;
      for(auto [uw, u] : graph[v]) {
        if(w + uw < dist[u]) {
          pq.emplace(dist[u] = w + uw, u);
        }
      }
    }
    return dist;
  };
  auto dist1 = f(0), dist2 = f(N-1);
  int ans = -oo;
  for(int i = 0; i < N; i++) {
    if(dist1[i] != oo && dist2[i] != oo) {
      ans = max(ans, dist1[i] + dist2[i]);
    }
  }
  cout << ans;
  exit(0);
}