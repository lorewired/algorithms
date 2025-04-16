#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf LLONG_MAX
#define V vector
const int mod = 1e9+7;

signed main() {
  int n;
  cin >> n;
  auto m = V<V<int>>(n, V<int>(n));
  auto dist = V<V<int>>(n, V<int>(n, inf));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }
  int ci[] = {-1, 0, 1, 0}, cj[] = {0, 1, 0, -1};
  set<pair<int, pair<int, int>>> st;
  st.insert({0, {0, 0}});
  dist[0][0] = 0;
  while(st.size()) { 
    int i = st.begin()->second.first;
    int j = st.begin()->second.second;
    st.erase(st.begin());
    for(int k = 0; k < 4; k++) {
      int ii = ci[k] + i, jj = cj[k] + j;
      if(ii >= 0 && ii < n && jj >= 0 && jj < n && dist[i][j]+m[ii][jj] < dist[ii][jj]) {
        st.erase({dist[ii][jj], {ii, jj}});
        dist[ii][jj] = dist[i][j]+m[ii][jj];
        st.insert({dist[ii][jj], {ii, jj}});
      }
    }
  }
  cout << dist[n-1][n-1];
  return 0;
}