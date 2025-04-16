#include <bits/stdc++.h>
using namespace std;

signed main() {
  int M, N;
  cin >> M >> N;
  map<string, int> mp;
  while (M--) {
    pair<string, int> p;
    cin >> p.first >> p.second;
    mp[p.first] = p.second;
  }
  cin.ignore();
  while (N--) {
    int T = 0;
    vector<string> W;
    string toadd;
    while (getline(cin, toadd) && toadd[0] != '.') {
      string str;
      for (char c : toadd) {
        if (c != ' ') str += c;
        else {
          W.push_back(str);
          str = "";
        }
      }
      W.push_back(str);
    }
    for (string S : W)
      if (mp.count(S))
        T += mp[S];
    cout << T << '\n';
  }
  return 0;
}