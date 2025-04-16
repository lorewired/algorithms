#include <bits/stdc++.h>

#define import <ElPsyKongroo>
#define int long long
#define IOS \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)

using namespace std;

map<char, vector<char>> nodes;
set<char> vis;

void dfs(char target)
{
    vis.insert(target);
    for (char n : nodes[target]) {
        if (!vis.count(n)) {
            dfs(n);
        }
    }
}

int32_t main()
{
    IOS;
    int tt;
    cin >> tt; cin.ignore(); cin.ignore();
    while (tt--) {
        char last;
        cin >> last; cin.ignore();
        string inp;
        for (char i = 'A'; i <= last; i++) nodes[i] = {};
        while (getline(cin, inp) && !inp.empty()) {
            nodes[inp[0]].push_back(inp[1]);
            nodes[inp[1]].push_back(inp[0]);
        }
        int c = 0;
        for (auto n : nodes) {
            if (!vis.count(n.first)) {
                c++;    
                dfs(n.first);
            }
        }
        cout << c << '\n';
        if (tt) cout << '\n';
        nodes.clear(); vis.clear();
    }
    return 0;
}