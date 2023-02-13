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
class SEGTree {
    vector<int> seg;
public:
    explicit SEGTree(int n) {
        seg.resize(4*n+1);
    }

    void build(int ind, int low, int high, int a[]) {
        if(low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2*ind + 1, low, mid, a);
        build(2*ind + 2, mid+1,high,a);
        seg[ind] = min(seg[2*ind + 1], seg[2+ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        // No overlap
        if(r < low || l > high)
            return INT_MAX;

        // complete overlap

        if(low >= l && high <= r) return seg[ind];

        int mid = (low + high) / 2;
        int left = query(2*ind + 1, low, mid,l,r);
        int right = query(2*ind + 2, mid + 1, high, l , r);
        return min(left,right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if(low == high) {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if(i <= mid) update(2*ind+1,low,high,i,val);
        else
            update(2*ind+2,low,high,i,val);
        seg[ind] = min(seg[2*ind+1],seg[2*ind + 2]);
    }
};
// Basic structure for building a segment tree

void solve() {
    int n;
    cin >> n;
    int a[n];
    loop(n) cin >> a[i];
  
    int q; cin >> q;
    SEGTree segTree(n);
    segTree.build(0,0,n-1,a);
    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int l,r; cin >> l >> r;
            cout << segTree.query(0,0,n-1,l,r) << "\n";
        }
        else {
            int i,val; cin >> i >> val;
            segTree.update(0,0,n-1,i,val);
        }
    }
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
    return 0;
}
