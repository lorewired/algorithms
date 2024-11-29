#include <bits/stdc++.h>
using namespace std;

char m[501][501];
int x,y;
void flood(int i, int j) {
   if (i < 0 || i >= x || j < 0 || j >= y || m[i][j] == 'o') {
      return;
   }
   m[i][j] = 'o';
   if (i+1 < x) {
      if (m[i+1][j] == '#') {
         flood(i , j+1);
         flood(i , j-1);
      } else {
         flood(i+1 ,j);
      }
   }
}

signed main () {
   int r, c;
   cin >> x >> y;
   for (int i = 0; i < x; i++) {
      string str;
      cin >> str;
      for (int j = 0; j < y; j++) {
         m[i][j] = str[j];
         if (m[i][j] == 'o') {
            r = i;
            c = j;
         }
      }
   }
   m[r][c] = '.';
   flood(r, c);
   for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++)
         cout << m[i][j];
      cout << '\n';
   }
   return 0;
}