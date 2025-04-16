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
  set<string> st;
  while (n--) {
    string str;
    cin >> str;
    if (st.count(str)) cout << "YES\n";
    else {
      cout << "NO\n";
      st.insert(str);
    }
  }
  return 0;
}