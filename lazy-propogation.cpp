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
    vector<int> seg, lazy;
public:
    ST(int n) {
        seg.resize(4 * n);
        lazy.resize(4 * n);
    }
public:
    void build(int ind, int low, int high, int arr[]) {
        if(low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
public:
    void update(int ind, int low, int high, int l, int r,int val) {
        // update the previous remaining updates
        // and propogate downwards
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            // propogate the lazy update downwards
            // for the remaining nodes to get updated
            if(low != high) {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }

            lazy[ind] = 0;
        }

        // no overlap
        // we don't do anything and return
        // low high l r or l r low high
        if(high < l or r < low) {
            return;
        }

        // complete overlap
        // l low high r
        if(low>=l && high <= r) {
            seg[ind] += (high - low + 1) * val;
            // if a leaf node, it will have childrens
            if(low != high) {
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }
        // last case has to be no overlap casei
        int mid = (low + high) >> 1;
        update(2*ind+1, low, mid, l, r, val);
        update(2*ind+2, mid+1, high, l, r, val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
public:
    int query(int ind, int low, int high, int l, int r) {

        // update if any updates are remaining
        // as the node will stay fresh and updated
        if(lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            // propogate the lazy update downwards
            // for the remaining nodes to get updated
            if(low != high) {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }

            lazy[ind] = 0;
        }

        // no overlap return 0;
        if(high < l or r < low) {
            return 0;
        }

        // complete overlap
        if(low>=l && high <= r) return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return left + right;
    }
};

void solve() {
    int n;
    cin >> n;
    int a[n];
    loop(n) cin >> a[i];
    ST st(n);
    st.build(0,0,n-1,a);

    int q;
    cin >> q;
    while(q--) {
        int type; cin >> type;

        if(type == 1) {
            int l,r,val;
            cin >> l >> r >> val;
            st.update(0,0,n-1,l,r,val);
        }
        else {
            int l,r;
            cin >> l >> r;
            cout << st.query(0,0,n-1,l,r) << "\n";
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

}