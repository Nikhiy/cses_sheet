#include<bits/stdc++.h>
using namespace std;
int fun(int i,int j,string& a,string& b,vector<vector<int>>& dp){
    int n=a.size();
    int m=b.size();
    if(i==n && j==m) return 0;
    if(i==n || j==m){
        if(i==n) return m-j;
        return n-i;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j]=fun(i+1,j+1,a,b,dp);
    return dp[i][j]=1+min({fun(i+1,j,a,b,dp),fun(i+1,j+1,a,b,dp),fun(i,j+1,a,b,dp)});
}
int main(){
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans=fun(0,0,a,b,dp);
    cout<<ans;
    return 0;
}