//
// Created by Ani Hadagali on 28/02/23.
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


int main () {
    //
    int n;
    cin >> n;

    int wt[] = {3,1,7};
    int val[] = {10,15,20};

    int dp[8][4] = {0};

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 8; j++) {
            if(j < wt[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                
            }
        }
    }

    return 0;
}