#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> m;

void flood (int i, int j) {
   if (i >= 0 && i < 5 && j >= 0 && j < 5 && !m[i][j]) {
      m[i][j] = 1;
      flood(i-1, j);
      flood(i, j-1);
      flood(i+1, j);
      flood(i, j+1);
   }
}

signed main() {
   int x;
   cin >> x;
   while (x--) {
      for (int i = 0; i < 5; i++) {
         vector<int> t(5);
         for (int j = 0; j < 5; j++)
            cin >> t[j];
         m.push_back(t);
      }
      flood(0, 0);
      cout << (m[4][4] == 1 ? "COPS" : "ROBBERS") << '\n';
      m.clear();
   }
   return 0;
}