#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n;
  while (cin >> n && n != 0) {
    map<string, string> m;
    string N, S;
    int T = 0;
    while (n--) {
      cin >> N >> S;
      m[N] = S;
    }
    cin >> n;
    while (n--) {
      cin >> N >> S;
      int diff = 0;
      for (int i = 0; i < S.size(); i++) {
        if (S[i] != m[N][i])
          diff++;
      }
      if (diff > 1)
        T++;
    }
    cout << T << '\n';
  }
  return 0;
}