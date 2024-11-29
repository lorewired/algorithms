#include <bits/stdc++.h>
using namespace std;

signed main() {
   int x;
   cin >> x;
   while (x--) {
      float total = 0;
      map<string, float> m;
      int n;
      cin >> n;
      while (n--) {
         pair<string, float> p;
         cin >> p.first >> p.second;
         m[p.first] = p.second;
      }
      cin >> n;
      while (n--) {
         pair<string, int> q;
         cin >> q.first >> q.second;
         total += m[q.first] * q.second;
      }
      cout << fixed << setprecision(2) << "R$ " << total << '\n';
   }
   return 0;
}