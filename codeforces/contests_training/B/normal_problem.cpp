#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    string s;
    cin>>s;
    for(int i=s.size()-1; i>=0; i--) {
        if(s[i]=='p') cout<<'q';
        else if(s[i]=='q') cout<<'p';
        else cout<<'w';
    }
    cout<<'\n';
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}