#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

using pis = pair<int, string>;

map<string, vector<string>> adj;
set<string> vis;

void bfs(string src, string dst) {
    queue<pis> q;
    q.push({0, src});
    vis.insert(src);

    map<string, string> par;
    priority_queue<pis, vector<pis>, greater<pis>> pq;

    while(q.size()) {
        pis cur = q.front(); q.pop();

        if(cur.second == dst) {
            pq.push(cur);
        } else {
            cur.first++;
            for(auto u : adj[cur.second]) {
                if(!vis.count(u)) {
                    q.push({cur.first, u});
                    vis.insert(u);
                    par[u] = cur.second;
                }
            }
        }
    }

    if(pq.empty()) {
        cout<<"No route\n";
        return;
    }

    vector<pair<string, string>> ans;
    string cur = pq.top().second;
    while(cur != src) {
        string p = par[cur];
        ans.push_back({p, cur});
        cur = p;
    }
    

    reverse(ans.begin(), ans.end());
    for(auto [p, ch] : ans) cout << p << ' ' << ch << '\n';
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int n, first = 1;
    while(cin >> n) {
        if(!first) cout<<'\n';
        first = 0;
        adj.clear();
        vis.clear();
        while(n--) {
            string x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        string src, dst;
        cin >> src >> dst;
        bfs(src, dst);
    }
    return 0;
}