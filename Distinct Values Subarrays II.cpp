#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=0;
    map<int,int> mpp;
    long long ans=0;
    for(int j=0;j<n;j++){
        mpp[arr[j]]++;
        while(mpp.size()>x){
            mpp[arr[i]]--;
            if(mpp[arr[i]]==0) mpp.erase(arr[i]);
            i++;
        }
        ans+=(j-i+1);
    }
    cout<<ans;
    return 0;
}