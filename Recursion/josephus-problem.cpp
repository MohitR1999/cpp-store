#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ull> vull;
typedef pair<int, int> ii;
typedef vector<ii> vpii;
typedef set<int> si;
typedef map<int, int> mii;
typedef unordered_map<string, int> uii;
typedef map<string, int> msi;
typedef unordered_map<string, int> usi;
typedef map<char, int> mci;
typedef unordered_map<char, int> uci;

void solve(vi arr, int k, int index, int &ans) {
    if (arr.size() == 1) {
        ans = arr[0];
    }
    else {
        index = (index + k) % arr.size();
        arr.erase(arr.begin() + index);
        solve(arr, k, index, ans);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for(int i = 0; i < arr.size(); i++) arr[i] = i+1;
        k--;
        int index = 0, ans = -1;
        solve(arr, k, index, ans);
        cout << ans << endl;
    }
    return 0;
}