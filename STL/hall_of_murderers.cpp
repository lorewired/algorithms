#include <bits/stdc++.h>
using namespace std;

signed main() {
  string N, M;
  set<string> deads;
  map<string, int> m;
  while (cin >> N >> M) {
    m[N]++;
    deads.insert(M);
  }
  for (const auto d : deads)
    if (m.count(d))
      m.erase(m.find(d));
  cout << "HALL OF MURDERERS\n";
  for (const auto& e : m)
    cout << e.first << ' ' << e.second << '\n';
  return 0;
}