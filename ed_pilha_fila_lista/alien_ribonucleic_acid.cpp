#include <bits/stdc++.h>
using namespace std;

signed main() {
   string str;
   while (cin >> str) {
      int cont = 0;
      stack<char> s;
      for (auto c : str) {
         if (!s.empty()) {
            if (c == 'C' && s.top() == 'F' || c == 'F' && s.top() == 'C' || c == 'B' && s.top() == 'S' || c == 'S' && s.top() == 'B') {
               s.pop();
               cont++;
            } else s.push(c);
         }
         else s.push(c);
      }
      cout << cont << '\n';
   }
   return 0;
}