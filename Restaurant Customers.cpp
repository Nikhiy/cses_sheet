#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    map<int,int> mpp;
    int ans=0,temp=0;
    for(auto it:arr){
        mpp[it[0]]++;
        mpp[it[1]]--;
    }
    for(auto it:mpp){
        temp+=it.second;
        ans=max(ans,temp);
    }
    cout<<ans;
    return 0;
}