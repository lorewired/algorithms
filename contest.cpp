#include <bits/stdc++.h>
#define import <ElPsyKongroo>
#define io ios_base::sync_with_stdio(false);
#define ll long long
using namespace std;

signed main()
{
    io;
    int arr[] {1, 2, 3, 4, 4, 5, 5};
    int arr_size = sizeof(arr)/4;
    int target = 4;
    int idx = upper_bound(arr, arr+arr_size, target) - arr;
    cout << idx << endl;
    return 0;
    int ans = -1;
    if (arr[idx] == target)
    {
        ans = arr[idx];
    }
    cout << (ans == -1 ? "numero nao encontrado\n" : "numero encontrado\n");
    return 0;
}