#include <bits/stdc++.h>
using namespace std;
int fun(int n,vector<int>& dp){
    if(n<0) return 1e9;
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    string temp=to_string(n);
    int ans=1e9;
    for(char c:temp){
        int val=c-'0';
        if(val!=0){
            int newval=1+fun(n-val,dp);
            ans=min(ans,newval);
        }
    }
    return dp[n]=ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    int temp= fun(n,dp);
    cout<<temp;
    return 0;
}