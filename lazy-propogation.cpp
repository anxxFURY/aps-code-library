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

// array sum in given range:

class ST {
    vector<int> st , lazy;
public:
    ST(int n) {
        st.resize(4*n),lazy.resize(4*n);
    }

    void build(int ind, int low, int high, int a[]) {
        if(low == high) {
            st[ind] =   a[low];
            return ;
        }

        int mid = (low + high) / 2;

        build(2*ind+1, low, mid, a);
        build(2*ind+2,mid+1,high,a);
        st[ind] = st[2*ind+1] + st[2*ind+2];
    }

    void update(int ind,int low, int high,int l, int r, int val) {

    }
};


void solve() {

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