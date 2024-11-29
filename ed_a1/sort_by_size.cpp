#include <bits/stdc++.h>
using namespace std;

signed main() {
  int N;
  cin >> N; cin.ignore();
  while (N--) {
    string S, T;
    getline(cin, S);
    vector<string> v, tmp;
    for (char c : S) {
      if (c != ' ')
        T += c;
      else {
        v.push_back(T);
        T = "";
      }
    }
    v.push_back(T);
    stable_sort(v.begin(), v.end(), [tmp] (string s1, string s2) {
      return s1.size() == s2.size() ? false : s1.size() > s2.size();
    });
    for (int i = 0; i < v.size(); i++)
      cout << v[i] << (i+1 == v.size() ? '\n' : ' ');
  }
  return 0;
}