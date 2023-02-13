#include <iostream>
#include "algorithm"
#include "vector"
#include "list"
#include "utility"
#include "unordered_map"
using namespace std;
#define ll long long int
#define prlong long int(n) cout << n;
#define loop(n) for(long long int i = 0; i < n; i++)
#define rloop(n) for(long long int j = n-1; j>0; j--)

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(pow(2,n),INT_MAX);
    dp[0] = 0;
    vector<vector<int>> arr;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int mask =0; mask < pow(2,n); mask++) {
        int x = 0;
        int k = mask;

        while(k) {
            x += k & 1;
            k >>= 1;
        }
        int r =1;
        for(int j = 0; j < n; j++) {
            if((r & mask) == 0) {
                dp[mask | r] = min(dp[mask | r], (dp[mask]) + arr[x][j]);
            }
            r << 1;
        }
    }

    cout << dp[pow(2,n) - 1] << endl;

}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int t;
    cin >> t;
    while(t--) {
        solve();
    }

}
