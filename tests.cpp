#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define sz(x) (int)x.size()
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.pb({x, i+1});
	}
	sort(a.begin(), a.end(), [](pair<int, int> p1, pair<int, int> p2){return p1.f < p2.f;});
	while (m--) {
		int x;
		cin >> x;
		
	}
	return 0;
}

// lower_bound(v.begin(), v.end(), alvo)    -> primeiro valor ou o primeiro maior valor que o meu alvo
// upper_bound(v.begin(), v.end(), alvo)                           -> primeiro maior valor