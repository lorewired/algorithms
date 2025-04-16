#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

using pi = pair<int,int>;
vector<vector<int>> dist, vis;
const int ci8[]={2,2,-1,1,-2,-2,-1,1}, cj8[]={-1,1,2,2,-1,1,-2,-2};

int bfs(pi start, pi end) {
    queue<pi> q;
    q.push(start);
    vis[start.first][start.second]=1;
    dist[start.first][start.second]=0;
    vector<vector<pi>> par(8, vector<pi>(8));
    while(q.size()) {
        auto [i,j]=q.front();
        q.pop();
        for(int k=0; k<8; k++) {
            int ii=i+ci8[k], jj=j+cj8[k];
            if(ii>=0 && ii<8 && jj>=0 && jj<8 && !vis[ii][jj] && dist[ii][jj]==-1) {
                q.push({ii,jj});
                vis[ii][jj]=1;
                dist[ii][jj]=dist[i][j]+1;
                par[ii][jj]={i,j};
            }
        }
    }
    int ans=0;
    pi cur=end;
    while(cur!=start) {
        ans++;
        cur=par[cur.first][cur.second];
    }
    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    string s, e;
    while(cin>>s>>e) {
        dist.assign(8, vector<int>(8,-1));
        vis.assign(8, vector<int>(8,0));
        pi start={s[1]-'0'-1, s[0]-'a'};
        pi end={e[1]-'0'-1, e[0]-'a'};
        int ans=bfs(start,end);
        cout<<"To get from "<<s<<" to "<<e<<" takes "<<ans<<" knight moves.\n";
    }
    return 0;
}