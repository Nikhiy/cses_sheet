#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    map<long long,long long> mpp;
    mpp[0]=1;
    long long temp=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        temp+=arr[i];
        long long diff=temp-x;
        if(mpp.find(diff)!=mpp.end()){
            ans+=mpp[diff];
        }
        mpp[temp]++;
    }
    cout<<ans;
    return 0;
}