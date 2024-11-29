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
         else {
            s.insert(w);
            if (!s.count(w)) count++;
            w.clear();  
         }
      }
      for (auto it : s)
         cout << it << (count2+1 == count ? "" : " ");
      cout << '\n';
   }
   return 0;
}