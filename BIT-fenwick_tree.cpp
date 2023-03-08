//
// Created by Ani Hadagali on 17/02/23.
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

class BIT {
public:
    int n;
    vector<int> bit;

    BIT(int n) {
        this -> n = n;
        bit.resize(n+1);
    }

    void update_util(int ind, int delta) {

        while (ind <= n) {
            bit[ind] += delta;
            ind += (ind & -ind);
        }
    }

    void buildBIT(int a[]) {
        loop(n+1)
            bit[i] = 0;

        for(int i = 0; i < n; i++)
            update_util(i+1,a[i]);

    }

    void update(int a[],int ind, int val) {
        int delta = val - a[ind];
        a[ind] = val;
        update_util(ind+1,delta);
    }

    int sum_till_n(int ind) {
        int sum = 0;

        while(ind > 0) {
            sum += bit[ind];
            ind -= ind & -ind;
        }
        return sum;
    }


    int query(int l , int r) {
        return sum_till_n(r+1) - sum_till_n(l);
    }
};



void solve() {
    int n;
    cin >> n;
    int arr[n];
    loop(n)
        cin >> arr[i];
    BIT bit(n);
    bit.buildBIT(arr);
    int q;
    cin >> q;

    while (q--) {
        int l,r;
        cin >> l >> r;
        cout << bit.query(l,r) << endl;
    }
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int t;
    //cin >> t;
    t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
