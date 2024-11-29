#include <bits/stdc++.h>
using namespace std;

signed main() {
   int n, m;
   cin >> n >> m;
   int x = n * m;
   vector<string> v, d;
   while (x--) {
      string cell;
      cin >> cell;
      if (cell[1] == 'V')
         v.push_back(cell);
      else
         d.push_back(cell);
   }
   auto sort_vec = [] (vector<string>& vec) {
      sort(vec.begin(), vec.end(), [] (string c1, string c2) {
         return c1[0] - '0' > c2[0] - '0';
      });
   };
   auto show_vec = [] (vector<string>& vec) {
      for (auto i : vec)
         cout << i << '\n';
   };
   sort_vec(v);
   sort_vec(d);
   show_vec(v);
   show_vec(d);
   return 0;
}