#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    sort(nums.begin(),nums.end());
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<=x;i++){
        if(i%nums[0]==0) dp[0][i]=1;
    }
    for(int ind=1;ind<n;ind++){
        for(int left=0;left<=x;left++){
            int notpick=dp[ind-1][left]%MOD;
            int pick=0;
            if(left-nums[ind]>=0) pick=dp[ind][left-nums[ind]]%MOD;
            dp[ind][left]=(pick+notpick)%MOD;
        }
    }
    cout<<dp[n-1][x];
    return 0;
}