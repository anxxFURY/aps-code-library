//
// Created by Ani Hadagali on 13/02/23.
//
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

class Info {
public:
    int open,close,full;
    Info() {
        open = 0;
        close = 0;
        full = 0;
    }
    Info(int _open, int _close, int _full) {
        open = _open;
        close = _close;
        full = _full;
    }
};


Info merge(Info left, Info right) {
    Info ans = Info(0, 0, 0);
    ans.full = left.full + right.full + min(left.open, right.close);
    ans.open = left.open + right.open - min(left.open, right.close);
    ans.close = left.close + right.close - min(left.open, right.close);

    return ans;
}

void build(int ind, int low, int high, string s, Info seg[]) {
    if(low == high) {
        seg[ind].close = s[low] == ')';
        seg[ind].open = s[low] == '(';
        seg[ind].full = 0;
        return;
    }
    int mid = (low + high) / 2;
    build(2*ind + 1,low,mid,s,seg);
    build(2*ind+ 2, mid+1,high,s,seg);
    seg[ind] = merge(seg[2*ind + 1],seg[2*ind + 2]);
}


Info query(int ind, int low, int high, int l , int r, Info seg[]) {
    if(r < low || high < l) return Info();

    if(l <= low && high <= r) return seg[ind];
    int mid = (low + high) / 2;
    Info left = query(2*ind + 1, low, mid, l, r,seg);
    Info right = query(2*ind + 2, mid +1, high, l,r,seg);
    return merge(left,right);
}

void solve() {
    // Codeforces code:
    // Count the max length of valid brackets
    // EX : )()(()))((
    // output :6 Explanation, Length = 6 [valid : () and (())]

    int n;
    string s;
    cin >> s;
    n = s.size();
    Info seg[4*n];
    build(0,0,n-1,s,seg);

    int q; cin>> q;
    while(q--) {
        int l, r; cin >> l >> r;
        l, r; // 0 based indexing
        Info ans = query(0,0,n-1,l,r,seg);
        cout << ans.full * 2 << "\n";
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
