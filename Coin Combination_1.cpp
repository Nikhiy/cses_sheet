#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int mod = 1e9+7;
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int sum=1;sum<=x;sum++){
        for(int j=0;j<n;j++){
            if(sum>=coins[j]){
                dp[sum] = (dp[sum] + dp[sum-coins[j]])%mod;
            }
        }
    }
    cout<<dp[x];
    return 0;
}