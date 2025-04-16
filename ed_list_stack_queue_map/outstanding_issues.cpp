#include <bits/stdc++.h>
using namespace std;

signed main() {
   string str;
   cin >> str;
   stack<char> s;
   for (char c : str)
      if (c == '(') s.push(c);
      else if (!s.empty()) s.pop();
   cout << (s.empty() ? "Partiu RU!" : "Ainda temos " + to_string(s.size()) + " assunto(s) pendente(s)!") << '\n';
   return 0;
}