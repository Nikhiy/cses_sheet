#include <bits/stdc++.h>
using namespace std;
bool fun(int ind,int sum,vector<int>& arr,vector<vector<int>>& dp){
    int n=arr.size();
    if(ind==n){
        return true;
    }
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    bool skip=fun(ind+1,sum,arr,dp);
    bool pick=fun(ind+1,sum+arr[ind],arr,dp);
    return skip|| pick;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> dp(n+1,vector<int>(100000,-1));
    bool t=fun(0,0,arr,dp);
    return 0;
}