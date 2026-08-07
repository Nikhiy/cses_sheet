#include <bits/stdc++.h>
using namespace std;
bool fun(long long val,int lim,vector<int>& arr){
    int n=arr.size();
    int now=1;
    long long temp=0;
    for(int i=0;i<n;i++){
        if(arr[i]>val) return false;
        temp+=arr[i];
        if(temp>val){
            now++;
            temp=arr[i];
        }
    }
    return now<=lim;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    long long i=0,j=1e18;
    while(i<=j){
        long long mid = i + (j - i) / 2;
        if(fun(mid,x,arr)){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    cout<<i;
    return 0;
}