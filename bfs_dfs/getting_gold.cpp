#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

vector<vector<char>> matrix;
vector<vector<bool>> vis;
int n, m, ans=0;

void search(int i, int j) {
    if(matrix[i][j]=='#' || vis[i][j]) return;
    vis[i][j]=1;
    if(matrix[i][j]=='G') {
        ans++;
        matrix[i][j]='.';
    }
    if(matrix[i-1][j]!='T' && matrix[i][j+1]!='T' && matrix[i+1][j]!='T' && matrix[i][j-1]!='T') {
        search(i-1,j);
        search(i,j+1);
        search(i+1,j);
        search(i,j-1);
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    while(cin>>m>>n) {
        matrix.assign(n, vector<char>(m));
        vis.assign(n, vector<bool>(m,0));
        int x, y;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin>>matrix[i][j];
                if (matrix[i][j]=='P') {
                    x=i; y=j;
                }
            }
        }
        search(x,y);
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}