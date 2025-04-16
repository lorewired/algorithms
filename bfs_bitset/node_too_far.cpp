#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*   /\_/\
*   (= ._.)
*   / >  \>
*/

map<int, vector<int>> network;

int bfs(int node, int ttl) {
    queue<pair<int,int>> q;
    set<int> used;
    q.push({node,ttl});
    used.insert(node);
    
    int c=1;
    while(q.size() && ttl) {
        auto [cur, cur_ttl]=q.front();
        q.pop();
        if(cur_ttl) {
            cur_ttl--;
            for(int conn : network[cur]) {
                if(!used.count(conn)) {
                    q.push({conn,cur_ttl});
                    used.insert(conn);
                    c++;
                }
            }
        }
    }

    return network.size()-c;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    int nc, c=1;
    while(cin>>nc && nc) {
        int node, ttl, inp=nc;
        network.clear();
        while(cin>>node>>ttl && node || ttl) {
            if(inp) {
                inp--;
                network[node].push_back(ttl);
                network[ttl].push_back(node);
            } else {
                int ans=bfs(node, ttl);
                cout<<"Case "<<c++<<": "<<ans<<" nodes not reachable from node "<<node<<" with TTL = "<<ttl<<".\n";
            }
        }
    }
    return 0;
}