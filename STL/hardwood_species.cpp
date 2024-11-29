#include <bits/stdc++.h>
using namespace std;

signed main() {
  string str;
  int n;
  cin >> n;
  cin.ignore();
  getline(cin, str);
  while (n--) {
    int total = 0;
    map<string, float> m;
    while (getline(cin, str) && !str.empty()) {
      m[str]++;
      total++;
    }
    for (const auto& e : m) {
      cout << fixed << setprecision(4) << e.first << ' ' << e.second * 100 / total << '\n';
    }
    cout << (n == 0 ? "" : "\n");
  }
  return 0;
}