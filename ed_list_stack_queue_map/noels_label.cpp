#include <bits/stdc++.h>
using namespace std;

signed main() {
   int n;
   cin >> n;
   map<string, string> m;
   cin.ignore();
   while (n--) {
      pair<string, string> q;
      getline(cin, q.first);
      getline(cin, q.second);
      m[q.first] = q.second;
   }
   cin >> n;
   cin.ignore();
   vector<pair<string, string>> p;
   while (n--) {
      pair<string, string> q;
      getline(cin, q.first);
      getline(cin, q.second);
      p.push_back(q);
   }
   for (auto i : p)
      cout << i.first << '\n' << m[i.second] << "\n\n";
   return 0;
}