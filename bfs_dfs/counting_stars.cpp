#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

int n, m, ans, ci8[]={-1,0,1,0,-1,-1,1,1}, cj8[]={0,1,0,-1,-1,1,-1,1};
vector<vector<int>> a, vis;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    while(cin>>n>>m && n && m) {
        a.assign(n,vector<int>(m));
        vis.assign(n,vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                char c;
                cin>>c;
                a[i][j]=c;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(a[i][j]==42 && !vis[i][j]) {
                    bool val=true;
                    for(int k=0; k<8 && val; k++) {
                        int ii=i+ci8[k], jj=j+cj8[k];
                        if(ii>=0 && ii<n && jj>=0 && jj<m && a[ii][jj]==42)
                            val=false;
                    }
                    if(val) ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}