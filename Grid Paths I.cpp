#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n,0));
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char temp;
            cin>>temp;
            if(temp=='*') grid[i][j]=1;
        }
    }
    dp[n-1][n-1]=1;
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            int right=0,down=0;
            if(j+1<n) right=dp[i][j+1]%MOD;
            if(i+1<n) down=dp[i+1][j]%MOD;
            dp[i][j]=(right+down)%MOD;
        }
    }
    cout<<dp[0][0];
    return 0;
}