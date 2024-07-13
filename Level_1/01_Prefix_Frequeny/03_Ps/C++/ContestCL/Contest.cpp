#include<bits/stdc++.h>
using namespace std;
/*****************************************************/
#define ll long long
#define un unsigned
#define endl '\n'
#define FAST  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pre cout.precision(20);
/*****************************************************/
const double pi =  ::acos(-1);
const int N = 2e5 + 9, MOD = 1e9 + 7;
const ll OO = 0x3f3f3f3f3f3f3f3f;
/*****************************************************/
void Start_Contest () {
    FAST
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
/****************************************************/

void Solve () {
    int arr[3];
    for (int i = 0;i<3;i++){
        cin>>arr[i];
    }



    for (int i = 0;i<5 ; i++){
        int mn = INT_MAX;
        int idx = 0;
        for (int j = 0;j<3;j++){
            if (arr[j] < mn){
                mn = arr[j];
                idx = j;
            }
        }
        arr[idx]++;
    }

    
    int mul = arr[0] * arr[1] * arr[2];
    cout<<mul<<endl;
}

int main () {
    Start_Contest();
    int t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}
