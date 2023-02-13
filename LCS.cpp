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
    string s1,s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();
    int a[l1+1][l2+1];
    for (int i = 0; i < l1+1; ++i) {
        for (int j = 0; j < l2+1; ++j) {
            a[0][j] = 0; a[i][0] = 0;
        }
    }

    for(int i =1; i < l1+1; i++) {
        for(int j = 1; j < l2+1; j++) {
            if(s1[i-1] == s2[j-1])
                a[i][j] = a[i-1][j-1] + 1;
            else
                a[i][j] = max(a[i-1][j],a[i][j-1]);
        }
    }
    cout << a[l1][l2];
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