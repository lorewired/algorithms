#include <bits/stdc++.h>
using namespace std;

signed main() {
   int x;
   cin >> x;
   while (x--) {
      int n, cont = 0;
      cin >> n;
      string str, str2;
      cin >> str;
      map<char, char> m;
      for (int i = 0; i < n; i++) {
         m['A' + i] = str[i];
         str2 += 'A' + i;
      }
      for (auto& it : m)
         if (m[it.second] == it.first && it.first != it.second) {
            swap(m[it.first], m[it.second]);
            cont++;
         }
      str.clear();
      for (const auto& it : m)
         str += it.second;
      cout << (str == str2 && cont == 1 ? "There are the chance." : "There aren't the chance.") << '\n';
   }
   return 0;
}