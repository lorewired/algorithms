#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n;
  cin >> n;
  cin.ignore();
  string str;
  while (n--) {
    int count = 0, count2 = 0;
    set<string> s;
    getline(cin, str);
    string w;
    for (char c : str) {
      if (c != ' ') w += c;
      else if (!w.empty()) {
        s.insert(w);
        w.clear();
      }
    }
    if (!w.empty())
      s.insert(w);    
    bool first = true;
    for (auto& w : s) {
      cout << (!first ? ' ' : '\n') << w;
      first = false;
    }
  }
  return 0;
}