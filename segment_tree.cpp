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

struct Node {
    vector<int> a;
};

 class SGTree {
 public:
 	vector<Node> seg;
 public:
 	SGTree(int n) {
 		seg.resize(4 * n + 1);
 	}

     Node Merger(Node left,Node right) {
         vector<int> ans(left.a.size() + right.a.size());
         sort(left.a.begin(),left.a.end());
         sort(right.a.begin(),right.a.end());
         merge(left.a.begin(),left.a.end(),right.a.begin(),right.a.end(),ans.begin());
         Node aa;
         aa.a = ans;
         return aa;
     }
 	void build(int ind, int low, int high, int arr[]) {
 		if (low == high) {
 			seg[ind].a.push_back(arr[low]) ;
 			return;
 		}
 		int mid = (low + high) / 2;
 		build(2 * ind + 1, low, mid, arr);
 		build(2 * ind + 2, mid + 1, high, arr);
 		seg[ind] = Merger(seg[2 * ind + 1], seg[2 * ind + 2]);
 	}

 	Node query(int ind, int low, int high, int l, int r) {
 		// no overlap
 		// l r low high or low high l r
        if (r < low || high < l) return Node();

 		// complete overlap
 		// [l low high r]
 		if (low >= l && high <= r) return seg[ind];

 		int mid = (low + high) >> 1;
 		Node left = query(2 * ind + 1, low, mid, l, r);
 		Node right = query(2 * ind + 2, mid + 1, high, l, r);
 		return Merger(left, right);
 	}
 	void update(int ind, int low, int high, int i, int val) {
 		if (low == high) {
 			seg[ind].a.pop_back();
             seg[ind].a.push_back(val);
 			return;
 		}
 		int mid = (low + high) >> 1;
 		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
 		else update(2 * ind + 2, mid + 1, high, i, val);
 		seg[ind] = Merger(seg[2 * ind + 1], seg[2 * ind + 2]);
 	}
 };

void solve() {
    int n;
    cin >> n;
    int a[n];
    loop(n) cin >> a[i];
  
    int q; cin >> q;
    SGTree segTree(n);
    segTree.build(0,0,n-1,a);
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int x,k; cin >> x >> k;
            x -= 1;
            //cout << segTree.query(0,0,n-1,l,r) << "\n";
            segTree.update(0,0,n-1,x,k);
        }
        else {
            int x,y,k; cin >> x >> y >> k;
            if(x==y) {
                if(k > 1)
                    cout << "0\n";
                else
                    cout << segTree.seg[0].a[k-1] << "\n";
            }
            else if(k>y-x+1)
                cout << "0\n";
            else {
                x -= 1;
                y -= 1;
                segTree.query(0,0,n-1,x,y);
                k -= 1;
                cout << segTree.seg[0].a[k] << "\n";
            }
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
