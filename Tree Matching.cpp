#include<bits/stdc++.h>
using namespace std;
int fun(int node,vector<vector<int>>& adj,vector<int>& dp){
    if(dp[node]!=-1) return dp[node];
    int ans=0;
    for(auto it:adj[node]){
        if(!vis[it]){
            ans=max(ans,1+fun(it,adj,dp));
        }
    }
    return dp[node]=ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> adj(n);
    for(auto it:arr){
        int u=it[0],v=it[1];
        adj[u].push_back(v);
    }
    vector<int> dp(n,-1);
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dp[i]=fun(i,adj,dp);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,dp[i]);
    cout<<(ans+1)/2;
    return 0;
}