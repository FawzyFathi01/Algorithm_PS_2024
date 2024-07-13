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

void Pangram () {
    bool freq[30] = {false};
    int n;
    cin >> n;
    string str;
    cin >> str;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        if (freq[str[i] - 'a'] == (int)false) {
            count++;
            freq[str[i] - 'a'] = true;
        }
    }
    (count == 26) ? cout << "YES" << endl : cout << "NO" << endl;
}





int main () {
    Start_Contest();
    int t = 1;
    //cin >> t;
    while (t--) {
        Pangram();
    }

    return 0;
}
