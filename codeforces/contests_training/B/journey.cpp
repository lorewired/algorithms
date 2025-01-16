#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

void solve() {
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    int sum=a+b+c;
    int d=n/sum*3;
    if(n%sum==0) {
        cout<<d<<'\n';
    } else if(n%sum <= a) {
        cout<<d+1<<'\n';
    } else if(n%sum <= a+b) {
        cout<<d+2<<'\n';
    } else {
        cout<<d+3<<'\n';
    }
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--)
       solve();
    return 0;
}