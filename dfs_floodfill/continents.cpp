#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

const int ci[]={-1, 0, 1, 0};
const int cj[]={0, 1, 0, -1};

vector<vector<char>> a;
vector<vector<bool>> vis;
int n, m;
char conti;

int explore(int i, int j, int c) {
    vis[i][j]=1;
    for (int k=0; k<4; k++) {
        int ii=i+ci[k];
        int jj=j+cj[k];
        if (ii>=0 && ii<m && jj>=0 && jj<n) {
            if (!vis[ii][jj] && a[ii][jj]==conti)
                c = explore(ii, jj, c+1);
        }
    }
    if (i>=0 && i<m && j>=0 && j<n) {
        if (j==0 && !vis[i][n-1] && a[i][n-1]==conti)
            c = explore(i, n-1, c+1);
        if (j==m-1 && !vis[i][0] && a[i][0]==conti)
            c = explore(i, 0, c+1);
    }
    return c;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    while (cin >> m >> n) {
        a.assign(m, vector<char>(n));
        vis.assign(m, vector<bool>(n, 0));
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                cin>>a[i][j];
        int x, y, g=0;
        cin >> x >> y;
        conti=a[x][y];
        explore(x, y, 1);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j]==conti && !vis[i][j]) {
                    int c=explore(i, j, 1);
                    g=max(c,g);
                }
            }
        }
        cout<<g<<'\n';
    }
    return 0;
}