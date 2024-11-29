#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<string>reverse;
    int b;
    cin >> b;
    for(int c=0; c <= b;c++){
		int t=0;
		string a, palavra="";
		getline(cin,a);
		for(int i=0;i <= int(a.size());i++){
			if(a[i] != ' ' && a[i] != '\0')
			palavra+=a[i];
			else{
				reverse.push(palavra);
				palavra="";
				t++;
			}
		}
		while(t > 0){
			if(!reverse.empty()){
				cout << reverse.top();
				cout << ( t > 1 ? " " : "\0");
				reverse.pop();
			}
			t--;
		}
		cout << "\n";
	}
}