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
// Prefix_Sum
void Solve_1 () {
    int size;
    cin >> size;
    int arr[size];
    for (auto &i: arr) {
        cin >> i;
    }

    //1- Calculate PreFix_Sum

    // Array  :-  1 2 5 10 12 6  7
    // prefix :-  1 3 8 18 30 36 43
    // How ==>  prefix[i]= prefix[i-1] + array[i]
    int prefix[size];
    prefix[0] = arr[0];
    for (int i = 1; i < size; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    cout << "Prefix Array : - " << endl;
    for (auto i: prefix) {
        cout << i << ' ';
    }

    //2- Sum Of Range
    cout << endl;
    int q, a, b, res;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        //  if (a==0)res = prefix[b];
        //  else res = prefix[b] - prefix[a-1];
        (a == 0) ? res = prefix[b] : res = prefix[b] - prefix[a - 1];
        cout << "Sum from " << a << " to " << b << " : " << res << endl;
    }
}

void Solve_2() {
    int size;
    cin >> size;
    int arr[size];
    for (auto &i: arr) {
        cin >> i;
    }
    // Appear NumBer
    // Input Number / Range a , b
    // Prefix for Frequency Number 0 -> size-1
    // Answer Quire Rang

    int t, num, q, a, b, res;
    cin >> t;
    while (t--) {
        cin >> num >> q;
        // Calculate Frequency For Num
        int freSum[size];
        freSum[0] = 0 + (arr[0] == num);
        for (int i = 1; i < size; i++) {
            freSum[i] = freSum[i - 1] + (arr[i] == num);
        }
        // Quire Range
        for (auto i: freSum) {
            cout << i << " ";
        }
        cout << endl;
        while (q--) {
            cin >> a >> b;
            //if (freSum[a] == 0) res = freSum[b];
            //else res = freSum[b] - freSum[a];
            (freSum[a] == 0) ? res = freSum[b] : res = freSum[b] - freSum[a];
            cout << "Count of Appear Num ( " << num << " ) From " << a << " to " << b << " : " << res << endl;
        }

    }
}

void Solve_3() {
    // Task Other
    // Arr ==> a , b / Min ( Sum(a) - Sum(b) )

    cout<<"test";
}


// Partial_Sum
void Solve_4() {

    // Input Array
    int size;
    cin >> size;
    int arr[size + 1];

    for (int i = 1; i <= size; i++) {
        cin >> arr[i];
    }

    // Update Array  for Range
    // input Quire
    // a,b,k

    arr[0] = 0;
    int q, a, b, k;
    cin >> q;
    while (q--) {
        cin >> a >> b >> k;
        arr[a] += k, arr[b + 1] -= k;
    }
    for (int i = 1; i <= size; i++) {
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main () {
    Start_Contest();
    int t = 1;
    // cin >> t;
    while (t--) {
        Solve_4();
    }

    return 0;
}
