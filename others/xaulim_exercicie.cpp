#include <bits/stdc++.h>
using namespace std;

signed main() {
   int x;
   while (cin >> x) {
      int v[x], out[x];
      for (int i = 0; i < x; i++)
         cin >> v[i];
      sort(v, v+x, [] (int n1, int n2) {
         return n1 < n2;
      });
      int t1 = 0, t2 = x-1;
      for (int i1 = 1, i2 = 0, cont = 0; cont < 10; cont++, i1 += 2, i2 += 2) {
         out[i1] = v[t1++];
         out[i2] = v[t2--];
      }
      for (int n : out)
         cout << n << ' ';
   }
   return 0;
}