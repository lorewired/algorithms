#include <bits/stdc++.h>
using namespace std;

signed main() {
  int x, N, T = 0;
  cin >> x >> N;
  vector<pair<int, int>> v;
  for (int i = 0; i < x; i++) {
    int y;
    cin >> y;
    v.push_back({y, i});
  }
  sort(v.begin(), v.end(), [] (pair<int, int> n1, pair<int, int> n2) {
    if (n1.first != n2.first)
      swap(n1.second, n2.second);
    return n1.first < n2.first;
  });
  int l = 0, r = x - 1;
  while (l<r) {
    int half = (l + r) / 2;
    if (v[half].first >= N)
      r = half;
    else
      l = half+1;
  }
  cout << l << '\n';
  // lower_bound(v.begin(), v.end(), alvo)    -> primeiro valor ou o primeiro maior valor que o meu alvo
  // upper_bound(v.begin(), v.end(), alvo)                           -> primeiro maior valor
  return 0;
}