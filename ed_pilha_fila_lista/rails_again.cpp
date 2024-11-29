#include <bits/stdc++.h>
using namespace std;

signed main() {
   int n;
   while(cin >> n && n != 0) {
      auto read_dt = [n] (queue<char>& q) {
         for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            q.push(c);
         }
      };
      queue<char> inp, out;
      read_dt(inp); read_dt(out);
      stack<char> s;
      while (!inp.empty()) {
         if (!out.empty()) {
            if (!s.empty() && out.front() == s.top()) {
               out.pop();
               s.pop();
               cout << 'R';
            } else {
               if (inp.front() == out.front()) {
                  out.pop();
                  inp.pop();
                  cout << "IR";
               } else {
                  s.push(inp.front());
                  inp.pop();
                  cout << 'I';
               }
            }
         }
      }
      while (!s.empty() && !out.empty()) {
         if (s.top() == out.front()) {
            out.pop();
            s.pop();
            cout << 'R';
         } else {
            cout << " Impossible";
            break;
         }
      }
      cout << '\n';
   }
   return 0;
}