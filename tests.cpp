#include <bits/stdc++.h>
using namespace std;
int main() {
  int caso, size;
  cin >> caso;
  while(caso--){
    int maior=0, tam=0, seg=0, number[3], total=0;
    queue<int> que;
    cin >> size;
    int num[size];
    for(int cal=0; cal < size; cal++){
      cin >> num[cal];
      que.push(num[cal]);
      if(num[cal] > maior){
        maior=num[cal];
        number[0] = maior;
      }
  } for(int cal=0; cal < size; cal++){
    if(num[cal] < maior && num[cal] > seg){
        seg = num[cal];
        number[1] = seg;
      }
  } while(!que.empty()){
    if(que.front() == number[0]){
      total = que.front() - number[1];
      cout << total << ' ';
      total=0;
      que.pop();
    } else {
      total = que.front() - number[0];
      cout << total << ' ';
      total=0;
      que.pop();
    }
   } cout << '\n';
  }
}