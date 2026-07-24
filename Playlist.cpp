#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=0;
    map<int,int> mpp;
    int ans=0;
    for(int j=0;j<n;j++){
        mpp[arr[j]]++;
        while(mpp[arr[j]]>1){
            mpp[arr[i]]--;
            if(mpp[arr[i]]==0) mpp.erase(arr[i]);
            i++;
        }
        ans=max(ans,(int) mpp.size());
    }
    cout<<ans;
    return 0;
}