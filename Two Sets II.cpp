#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int fun(int ind,int left,vector<int>& arr,vector<vector<int>>& dp){
    int n=arr.size();
    if(left==0) return 1;
    if(ind==n) return 0;
    if(dp[ind][left]!=-1) return dp[ind][left];
    int notpick=fun(ind+1,left,arr,dp);
    int pick=0;
    if(arr[ind]<=left){
        pick=fun(ind+1,left-arr[ind],arr,dp);
    }
    return dp[ind][left]=(pick+notpick)%MOD;
}
int main(){
    int n;
    cin>> n;
    long long sum=(n*(n+1))/2;
    if(sum%2){
        int ans=0;
        cout<<ans;
        return 0;
    }
    vector<int> arr;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }
    vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
    int ans= fun(0,sum/2,arr,dp);
    cout << (1LL * ans * 500000004) % MOD;
    return 0;
}