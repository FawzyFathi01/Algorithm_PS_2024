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
void  Letter() {
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);

    map<char,int> m1;
    map<char,int> m2;

    for(int i = 0;i<(int)s1.length();i++){
        m1[s1[i]]++;
    }

    for(int i = 0;i<(int)s2.length();i++){
        m2[s2[i]]++;
    }

    m2.erase(' ');

    for (auto m : m2){

        if ( (m.second > m1[m.first] ) ){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}
void Good_Array () {
    /**
     * Algorithm
     * 1- Map <int , int > for element Array (arr) // frequency
     * 2- res = sumArray - arr[idx] , Res is Even only
     * 3- Check ( Res / 2 ) in map , spatial Cass (res / 2) == arr[i] && MyMap[res / 2] >= 2 , true ==> ans.Add(idx)
     *
     */
    // Improve this Code

    int n;
    cin >> n;
    ll arr[n];
    vector<ll> ans;
    map<ll, ll> MyMap;
    ll sum = 0;

    for (auto &item: arr) {
        cin >> item;
        sum += item * 1ll;
        MyMap[item]++;
    }


    // ✔ Sum , ✔ Map
    for (int i = 0; i < n; i++) {
        ll res = sum - arr[i];
        MyMap[arr[i]]--;
        if (res % 2 == 0 && MyMap[(res / 2)]) {
            ans.push_back(i);
        }
        MyMap[arr[i]]++;
    }

    cout << ans.size() << endl;
    for (auto item: ans) {
        cout << (item + 1) << " ";
    }
    cout << endl;


}



int main () {
    Start_Contest();
    int t = 1;
    //cin >> t;
    while (t--) {
        //Pangram();
        //Letter();
        Good_Array();
    }

    return 0;
}
