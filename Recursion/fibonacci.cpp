#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<char> vc;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef vector<ull> vull;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int helper(int n, vi &arr) {
    if (arr[n] != -1) {
        return arr[n];
    }
    else return arr[n] = helper(n-1, arr) + helper(n-2, arr);
}

int fibonacci(int N) {
    if (N == 0 || N == 1) return N;
    vi arr(N+1, -1);
    arr[0] = 0;
    arr[1] = 1;
    int num = helper(N, arr);
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fibonacci(8);
    return 0;
}