#include <bits/stdc++.h>
using namespace std;

typedef struct {
   string name;
   int g = 0;
   int s = 0;
   int b = 0;
} country;

signed main() {
   string comp, name;
   map<string, country> m;
   while (getline(cin, name)) {
      for (int i = 0; i < 3; i++) {
         getline(cin, name);
         if (m.count(name)) {
            if (i == 0) m[name].g++;
            if (i == 1) m[name].s++;
            if (i == 2) m[name].b++;
         } else {
            country me;
            me.name = name;
            if (i == 0) me.g++;
            if (i == 1) me.s++;
            if (i == 2) me.b++;
            m[name] = me;
         }
      }
   }
   vector<country> v;
   for (const auto& it : m)
      v.push_back(it.second);
   sort(v.begin(), v.end(), [] (country c1, country c2) {
      if (c1.g != c2.g)
         return c1.g > c2.g;
      if (c1.s != c2.s)
         return c1.s > c2.s;
      if (c1.b != c2.b)
         return c1.b > c2.b;
      return c1.name < c2.name;
   });
   cout << "Quadro de Medalhas\n";
   for (auto c : v)
      cout << c.name << ' ' << c.g << ' ' << c.s << ' ' << c.b << '\n';
   return 0;
}