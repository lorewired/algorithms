#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

using pi = pair<int,int>;
const int ci[]={2, 2, 1, -1, -2, -2, -1, 1}, cj[]={-1, 1, 2, 2, -1, 1, -2, -2};
vector<vector<int>> vis, dist;
pi st, ed;

int bfs() {
    queue<pi> qu;
    qu.push(st);
    vis[st.first][st.second]=1;
    dist[st.first][st.second]=0;

    vector<vector<pi>> parents(8, vector<pi>(8, {-1,-1}));
    while(qu.size()) {
        auto [i,j]=qu.front();
        qu.pop();
        for(int k=0; k<8; k++) {
            int ii=i+ci[k], jj=j+cj[k];
            if(ii>=0 && ii<8 && jj>=0 && jj<8 && !vis[ii][jj] && dist[ii][jj]==-1) {
                vis[ii][jj]=1;
                qu.push({ii,jj});   
                dist[ii][jj]=dist[i][j]+1;
                parents[ii][jj]={i,j};
            }
        }
    }

    int ans=0;
    pi cur=ed;
    while(cur != st) {
        auto [pi,pj]=parents[cur.first][cur.second];
        if(pi==-1 && pj==-1) break;
        ans++;
        cur={pi,pj};
    }
    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    string x, y;
    while(cin>>x>>y) {
        vis.assign(8,vector<int>(8,0));
        dist.assign(8,vector<int>(8,-1));
        st={x[1]-'0'-1, x[0]-'a'};
        ed={y[1]-'0'-1, y[0]-'a'};
        int ans=bfs();
        cout<<"To get from "<<x<<" to "<<y<<" takes "<<ans<<" knight moves.\n";
    }
    return 0;
}