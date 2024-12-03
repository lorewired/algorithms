#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()

void solve () {
  int s, t;
  cin >> s >> t;
  vector<int> bin(s), pref(s+1, 0);
  for (int &i : bin) cin >> i;
  for (int i = 0; i < s; i++)
    pref[i+1] = bin[i] + pref[i];
  
  int op = 0, l = s/2-1, r = s/2, flo = -1, fro = -1;
  bool s_o=0, t_found=0;


  while (l > -1 || r < s) {
    if (s_o) {
      flo = flo == -1 && bin[l] ? l : flo;
      fro = fro == -1 && bin[r] ? r : fro;
      if (flo!=-1 && fro!=-1)
        s_o = false;
    }
    if (flo != -1 && l>=0) op++;
    if (fro != -1 && r<s) op++;
    if (!t_found && pref[r] - pref[l-(!l ? 0 : 1)] == t) {
      s_o = true;
      t_found = true;
    }
    l--; r++;
  }
  cout << op << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
}