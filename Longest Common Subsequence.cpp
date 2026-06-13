#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        b.push_back(temp);
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans=dp[n][m];
    int i = n, j = m;
    vector<int> arr;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            arr.push_back(a[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(arr.begin(), arr.end());
    cout << dp[n][m] << "\n";
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}