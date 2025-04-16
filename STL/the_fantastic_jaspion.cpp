#include <bits/stdc++.h>
using namespace std;

signed main() {
  int x;
  bool fc = true;
  cin >> x;
  while (x--) {
    fc = false;
    int M, N;
    cin >> M >> N;
    cin.ignore();
    map<string, string> mp;
    while (M--) {
      string jp, td;
      getline(cin, jp);
      getline(cin, td);
      mp[jp] = td;
    }
    while (N--) {
      vector<string> v;
      string str, toadd;
      getline(cin, str);
      for (char c : str) {
        if (c != ' ')
          toadd += c;
        else {
          v.push_back(toadd);
          toadd = "";
        }
      }
      v.push_back(toadd);
      for (int i = 0; i < v.size(); i++)
        cout << (mp.count(v[i]) ? mp[v[i]] : v[i]) << (i+1 == v.size() ? "" : " ")  ;
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}