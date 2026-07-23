#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    long long ans=0;
    int mid=n/2;
    int val=arr[mid];
    for(int i=0;i<n;i++){
        ans+=abs(val-arr[i]);
    }
    cout<<ans;
    return 0;
}