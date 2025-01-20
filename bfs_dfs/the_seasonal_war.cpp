#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

char a[25][25];
int n, vis[25][25], ci8[]={-1,0,1,0,-1,-1,1,1}, cj8[]={0,1,0,-1,-1,1,-1,1};

void ff(int i, int j) {
    if(i<0 || i>=25 || j<0 || j>=25 || a[i][j]=='0' || vis[i][j])
        return;
    vis[i][j]=1;
    for(int k=0; k<8; k++) {
        int ii=i+ci8[k], jj=j+cj8[k];
        ff(ii,jj);
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    for(int k=1; cin>>n; k++) {
        memset(a,'0',sizeof(a));
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin>>a[i][j];
            }
        }
        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(a[i][j]=='1' && !vis[i][j]) {
                    ff(i,j);
                    ans++;
                }
            }
        }
        cout<<"Image number "<<k<<" contains "<<ans<<" war eagles.\n";
    }
    return 0;
}