#include <bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	string s;
	cin>>s;
	set<string> used;
	int c[4]={0};
	auto handle = [&](string num, char t, int n, int i){
		if(s[i+2]==t && c[n]!=-1) {
			if(used.count(num)) c[n]=-1;
			else {
				used.insert(num);
				c[n]++;
			}
		}
	};
	auto print = [&](int n){
		cout<<(c[n]==-1?"erro":to_string(13-c[n]))<<'\n';
	};
	for(int i=0; i<s.size(); i+=3) {
		string num; num+=s[i]; num+=s[i+1]; num+=s[i+2];
		handle(num, 'C', 0, i);
		handle(num, 'E', 1, i);
		handle(num, 'U', 2, i);
		handle(num, 'P', 3, i);
	}
	print(0);
	print(1);
	print(2);
	print(3);
	return 0;
}