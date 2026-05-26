#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,X;
    cin>>n>>X;
    vector<int> price;
    vector<int> page;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        price.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        page.push_back(temp);
    }
    vector<vector<int>> dp(n+1,vector<int>(X+1,0));
    for(int ind=n-1;ind>=0;ind--){
        for(int x=0;x<=X;x++){
            int notpick=dp[ind+1][x];
            int pick=0;
            if(price[ind]<=x) pick=page[ind]+dp[ind+1][x-price[ind]];
            dp[ind][x]=max(pick,notpick);
        }
    }
    cout<<dp[0][X];
    return 0;
}