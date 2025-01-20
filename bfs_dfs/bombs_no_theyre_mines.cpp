#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

using pi = pair<int,int>;
int land[1002][1002], dist[1002][1002], ci4[] = {-1, 0, 1, 0}, cj4[] = {0, 1, 0, -1};
int n, m;

int bfs(pi start, pi end) {
    queue<pi> q;
    q.push({end.first,end.second});
    dist[end.first][end.second] = 0;
    vector<vector<pi>> par(1002, vector<pi>(1002));

    while (q.size()) {
        auto [i,j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ii = i + ci4[k], jj = j + cj4[k];
            if (dist[ii][jj] == -1 && !land[ii][jj]) {
                q.push({ii,jj});
                dist[ii][jj] = dist[i][j] + 1;
                par[ii][jj] = {i,j};
            }
        }
    }

    int ans = 0;
    pi cur = start;
    while (cur != end) {
        cur = par[cur.first][cur.second];
        ans++;
    }

    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int rows;
    while(cin >> n >> m && n && m) {
        memset(land,0,sizeof(land));
        memset(dist,-1,sizeof(dist));
        cin >> rows; cin.ignore();
        while(rows--) {
            string l;
            getline(cin,l);
            stringstream ss(l);
            int r, bombj; ss >> r;
            while(ss >> bombj) {
                land[r+1][bombj+1] = 1;
            }
        }
        int s1, s2, e1, e2;
        cin >> s1 >> s2 >> e1 >> e2;
        pi start = {s1,s2}, end = {e1,e2};
        int ans = bfs(start,end);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << land[i][j];
            }
            cout << '\n';
        }
        cout<<ans<<'\n';
    }
    return 0;
}