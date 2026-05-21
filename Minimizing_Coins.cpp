#include<bits/stdc++.h>
using namespace std;
int fun(int ind,int x,vector<int>& arr,vector<vector<int>>& dp){
    if(ind==0){
        if(x%arr[0]==0) return x/arr[0];
        return 1e9;
    }
    if(dp[ind][x]!=-1) return dp[ind][x];
    int pick=1e9,notpick=1e9;
    notpick=fun(ind-1,x,arr,dp);
    if(arr[ind]<=x){
        pick=1+fun(ind,x-arr[ind],arr,dp);
    }
    return dp[ind][x]=min(pick,notpick);
}
int main(){
    int n,w;
    cin>>n;
    cin>>w;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        if(i%arr[0]==0){
            dp[0][i]=i/arr[0];
        }
        else{
            dp[0][i]=1e9;
        }
    }
    for(int ind=1;ind<n;ind++){
        for(int x=0;x<=w;x++){
            int pick=1e9,notpick=1e9;
            notpick=dp[ind-1][x];
            if(arr[ind]<=x){
                pick=1+dp[ind][x-arr[ind]];
            }
            dp[ind][x]=min(pick,notpick);
        }
    }
    if(dp[n-1][w] >= 1e9) cout << -1;
    else cout << dp[n-1][w];
    return 0;
}