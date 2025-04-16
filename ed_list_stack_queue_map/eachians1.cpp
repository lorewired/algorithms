#include <bits/stdc++.h>
using namespace std;

signed main() {
   string str;
   int cont = 0;
   map<string, vector<int>> m;
   while (cin >> str && str[0] > 60) {
      m[str].push_back(cont);
      cont += str.size() + 1;
   }
   int l = stoi(str);
   string v[l];
   for (int i = 0; i < l; i++)
      cin >> v[i];
   for (int i = 0; i < l; i++) {
      if (!m.count(v[i]))
         cout << -1;
      else
         for (int j = 0; j < m[v[i]].size(); j++)
            cout << m[v[i]][j] << (j+1 == m[v[i]].size() ? "" : " ");
      cout << '\n';
   }
   return 0;
}