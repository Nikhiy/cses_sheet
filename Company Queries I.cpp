#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> dp(n+1,vector<int>(20,-1));
    for(int i=2;i<=n;i++){
        cin>>dp[i][0];
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
          if(dp[i][j-1]!=-1) dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        for(int i=0;i<20;i++){
            if(v &(1<<i)){
                u=dp[u][i];
            }
            if(u==-1) break;
        }
        cout<<u<<' ';
    }
    return 0;
}