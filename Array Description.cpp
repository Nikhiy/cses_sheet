#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int fun(int ind,int prev,vector<int>& arr,int m,vector<vector<int>>& dp){
    int n=arr.size();
    if(ind==n) return true;
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    int ans=0;
    if(arr[ind]==0){
        if(ind==0){
            for(int i=1;i<=m;i++){
                // arr[0]=i;
                ans=(ans+fun(ind+1,i,arr,m,dp))%MOD;
                // arr[0]=0;
            }
        }
        else{
            if(prev-1>0){
                // arr[ind]=prev-1;
                ans=(ans+fun(ind+1,prev-1,arr,m,dp))%MOD;
                // arr[ind]=0;
            }
            // arr[ind]=prev;
            ans=(ans+fun(ind+1,prev,arr,m,dp))%MOD;
            // arr[ind]=0;
            if(prev+1<=m){
                // arr[ind]=prev+1;
                ans=(ans+fun(ind+1,prev+1,arr,m,dp))%MOD;
                // arr[ind]=0;
            }
        }
    }
    else{
        if(ind==0){
            ans=(ans+fun(ind+1,arr[0],arr,m,dp))%MOD;
        }
        else{
            if(abs(prev-arr[ind])==1 || abs(prev-arr[ind])==0){
                ans=(ans+fun(ind+1,arr[ind],arr,m,dp))%MOD;
            }
        }
    }
    return dp[ind][prev+1]=ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<vector<int>> dp(n,vector<int>(m+2,-1));
    int ans=fun(0,-1,arr,m,dp);
    cout<<ans;
    return 0;
}