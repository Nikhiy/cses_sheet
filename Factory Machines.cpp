#include<bits/stdc++.h>
using namespace std;
bool fun(long long val,int t,vector<int>& arr){
    int n=arr.size();
    long long ans=0;
    for(int i=0;i<n;i++){
        int pos=val/arr[i];
        ans+=pos;
        if(ans >= t) return true;
    }
    return ans>=t;
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    long long i=0,j=0;
    i=0LL;
    j=1LL*arr[0]*t;
    while(i<=j){
        long long mid=(i+j)/2;
        if(fun(mid,t,arr)){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    cout<<i;
    return 0;
}