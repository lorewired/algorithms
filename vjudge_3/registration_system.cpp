#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pi pair<int, int>
#define bg begin()
#define en end()
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<string, int> mp;
  while (n--) {
    string str;
    cin >> str;
    if (mp.count(str)) cout << str + to_string(mp[str]) << '\n';
    else cout << "OK\n";
    mp[str]++;
  }
  return 0;
}