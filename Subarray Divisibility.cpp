#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    map<long long,long long> mpp;
    long long ans=0;
    mpp[0]=1;
    long long temp=0;
    for(int i=0;i<n;i++){
        temp+=arr[i];
        long long mod = ((temp % n) + n) % n;
        if(mpp.find(mod)!=mpp.end()){
            ans+=mpp[mod];
        }
        mpp[mod]++;
    }
    cout<<ans;
    return 0;
}