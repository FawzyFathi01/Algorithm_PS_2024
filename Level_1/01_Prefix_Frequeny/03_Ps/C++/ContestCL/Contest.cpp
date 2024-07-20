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
const int N = 1e5+9, MOD = 1e9 + 7;
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
//Goal - ✔ , X

void Pangram () {
    bool freq[30] = {false};
    int n;
    cin >> n;
    string str;
    cin >> str;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        if (freq[str[i] - 'a'] == (int) false) {
            count++;
            freq[str[i] - 'a'] = true;
        }
    }
    (count == 26) ? cout << "YES" << endl : cout << "NO" << endl;
}

void  Letter() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    map<char, int> m1;
    map<char, int> m2;

    for (int i = 0; i < (int) s1.length(); i++) {
        m1[s1[i]]++;
    }

    for (int i = 0; i < (int) s2.length(); i++) {
        m2[s2[i]]++;
    }

    m2.erase(' ');
    for (auto m: m2) {

        if ((m.second > m1[m.first])) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

void Empty_array() {
    /**
     * Algorithm
     * 1- Map For Element array (frequency)
     * 2- iterate item map, if item.value ==0 then Skip (print item.key , item.value--) (n*m).
     *
     * Notes :-
     * 1- map.erase () !! with foreach
     * 2- To affect the item.value use & ref ==> for (auto item&:MyMap)
     */

    int n;
    cin >> n;
    map<int, int> myMap;
    int arr[n];

    for (auto &item: arr) {
        cin >> item;
        myMap[item]++;
    }

    while (n) {
        for (auto &item: myMap) {
            if (item.second == 0)continue;
            cout << item.first << " ";
            item.second--;
            n--;
        }
        cout << endl;
    }
}
void Worms () {
    /**
     * Algorithm
     * 1- Prefix Array For element Array
     * 2- Search Lower_bound as Find (Qa) or x : x first element large from ( Qa )
     * 3- Return Index for Res From Search.
     * */
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {

        int a;
        cin >> a;
        int it = lower_bound(v.begin(), v.end(), a) - v.begin();
        cout << it + 1 << endl;

    }
}
void Sereja_and_Suffixes () {
    /**
     * Algorithm
     * 1- Array Ans for count disc , set form end to begin Array
     * 2- insert set.count into Ans
     * */

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    set<int> disc;
    vector<int> ans(n);
    for (auto &item: arr)cin >> item;
    for (int i = n - 1; i >= 0; --i) {
        disc.insert(arr[i]);
        ans[i] = (int) disc.size();
    }
    while (m--) {
        int a;
        cin >> a;
        cout << ans[a - 1] << endl;
    }
}



ll arrInput [N] = {};
ll CounterArr[N] = {};
ll Quire[N] = {};

struct Triple {
    int x;
    int y;
    ll z;
};

void Greg_and_Array () {
    /**
     *
     * Algorithm :-
     * 1- Partial Sum For ArrQuire ( Update = 1 ), And prefix sum for ArrQuire
     * 2- Partial Sum For CounterArr After UpDate OperationArr with (d(tuple.z) * Quite[i] )
     * 3- Prefix Sum For CounterArr
     * 4- Res = (CounterArr After prefix) [i] * ArrInput [i]
     *
     * Note :-
     * 1- Global Array For Partial Sum if initialize by 0
     * 2- Prefix Sum for Partial Sum Only , Array + prefix
     */


    int n, m, k;
    vector<Triple> operation;
    cin >> n >> m >> k;

    // input Array
    for (int i = 1; i <= n; i++) {
        cin >> arrInput[i];
    }



    // input Operations
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        operation.push_back({a, b, c});
    }



    // input Quire
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        Quire[a]++;
        Quire[b + 1]--;
    }


    for (int i = 1; i <= m; i++) {
        Quire[i] += Quire[i - 1];
    }


    int j = 1;
    for (auto item: operation) {
        CounterArr[item.x] += (item.z * Quire[j]);
        CounterArr[item.y + 1] -= (item.z * Quire[j]);
        j++;
    }


    for (int i = 1; i <= n; i++) {
        CounterArr[i] += CounterArr[i - 1];
    }


    for (int i = 1; i <= n; i++) {
        ll ans = CounterArr[i] + arrInput[i];
        cout << ans << " ";
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
        //Good_Array();
        //Empty_array();
        //Worms();
        //Sereja_and_Suffixes();
        //Greg_and_Array();
    }

    return 0;
}
