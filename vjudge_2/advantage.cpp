#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int C, Q;
  cin >> C;
  while (C--) {
    cin >> Q;
    vector<int> v, cpy;
    int g = 0, g2 = 0;
    while (Q--) {
      int N;
      cin >> N;
      if (N > g)
        g = N;
      v.push_back(N);
    }
    cpy = vector<int>(v.begin(), v.end());
    sort(cpy.begin(), cpy.end());
    for (auto n : v)
      if (n == g)
        cout << n - cpy[v.size()-2] << ' ';
      else
        cout << n - g << ' ';
    cout << '\n';
  }
  return 0;
}