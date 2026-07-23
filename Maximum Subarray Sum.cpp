#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    long long temp=arr[0],ans=arr[0];
    for(int i=1;i<n;i++){
        temp=max(temp+arr[i],1LL*arr[i]);
        ans=max(ans,temp);
    }
    cout<<ans;
    return 0;
}