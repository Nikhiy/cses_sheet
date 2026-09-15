#include<bits/stdc++.h>
using namespace std;
static bool comp(vector<int>& a,vector<int>& b){
    return a[0]<b[0];
}
long long fun(int ind,vector<vector<int>>& arr,vector<long long>& dp){
    int n=arr.size();
    if(ind==n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    long long skip=fun(ind+1,arr,dp);
    long long pick=0;
    int over=arr[ind][1];
    int i=0,j=n-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(arr[mid][0]<=over){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    pick=arr[ind][2]+fun(i,arr,dp);
    return dp[ind]=max(pick,skip);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    sort(arr.begin(),arr.end(),comp);
    vector<long long> dp(n,-1);
    long long ans= fun(0,arr,dp);
    cout<<ans<<endl;
}