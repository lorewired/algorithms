#include <bits/stdc++.h>
using namespace std;

signed main() {
  map<string, string> m
  {
    {"brasil", "Feliz Natal!"},
    {"portugal", "Feliz Natal!"},
    {"alemanha", "Frohliche Weihnachten!"},
    {"austria", "Frohe Weihnacht!"},
    {"coreia", "Chuk Sung Tan!"},
    {"argentina", "Feliz Navidad!"},
    {"espanha", "Feliz Navidad!"},
    {"chile", "Feliz Navidad!"},
    {"mexico", "Feliz Navidad!"},
    {"grecia", "Kala Christougena!"},
    {"estados-unidos", "Merry Christmas!"},
    {"inglaterra", "Merry Christmas!"},
    {"australia", "Merry Christmas!"},
    {"antardida", "Merry Christmas!"},
    {"canada", "Merry Christmas!"},
    {"suecia", "God Jul!"},
    {"turquia", "Mutlu Noeller"},
    {"irlanda", "Nollaig Shona Dhuit!"},
    {"belgica", "Zalig Kerstfeest!"},
    {"italia", "Buon Natale!"},
    {"libia", "Buon Natale!"},
    {"marrocos", "Milad Mubarak!"},
    {"siria", "Milad Mubarak!"},
    {"japao", {"Merii Kurisumasu!"}}
  };
  string C;
  while (cin >> C)
    cout << (m.count(C) ? m[C] : "--- NOT FOUND ---") << '\n';
  return 0;
}