#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    map<int,int> mpp;
    int i=0;
    long long ans=0;
    for(int j=0;j<n;j++){
        mpp[nums[j]]++;
        while(mpp[nums[j]]>1){
            mpp[nums[i]]--;
            if(mpp[nums[i]]==0) mpp.erase(nums[i]);
            i++;
        }
        ans=1LL*ans+mpp.size();
    }
    cout<<ans;
    return 0;
}