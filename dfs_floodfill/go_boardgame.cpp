#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

using pib = tuple<int,bool,bool>;
vector<vector<char>> a;
vector<vector<bool>> vis;

const int ci[]={-1, 0, 1, 0};
const int cj[]={0, 1, 0, -1};

pib dfs(int i, int j, pib c) {
    vis[i][j]=1;
    get<0>(c)++;
    for (int k=0; k<4; k++) {
        int ii=i+ci[k];
        int jj=j+cj[k];
        if (ii>=0 && ii<9 && jj>=0 && jj<9 && !vis[ii][jj]) {
            if (a[ii][jj]=='X') get<1>(c)=1;
            if (a[ii][jj]=='O') get<2>(c)=1;
            if (a[ii][jj]=='.') c=dfs(ii, jj, c);
        }
    }
    return c;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        a.assign(9, vector<char>(9));
        vis.assign(9, vector<bool>(9, 0));
        int black=0, white=0;
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                cin>>a[i][j];
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (a[i][j]=='.' && !vis[i][j]) {
                    pib c=dfs(i, j, {0,0,0});
                    if (get<1>(c) && !get<2>(c)) black += get<0>(c);
                    if (!get<1>(c) && get<2>(c)) white += get<0>(c);
                } else if (a[i][j]!='.') {  
                    char oppo=a[i][j]=='X'?'O':'X';
                    int c=0;
                    for (int k=0; k<4; k++) {
                        int ii=i+ci[k];
                        int jj=j+cj[k];
                        if (ii>=0 && ii<9 && jj>=0 && jj<9 && a[ii][jj]==oppo)
                            c++;
                    }
                    if (c==4) {
                        if (a[i][j]=='X') white++;
                        else black++;
                    } else {
                        if (a[i][j]=='X') black++;
                        if (a[i][j]=='O') white++;
                    }
                }
            }
        }
        cout<<"Black "<<black<<" White "<<white<<'\n';
    }
    return 0;
}