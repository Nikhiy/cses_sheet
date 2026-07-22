#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    int ans=0;
    while(i<=j){
        if(i==j) {
            ans++;
            break;
        }
        int temp=arr[i]+arr[j];
        if(temp>x){
            j--;
        }
        else{
            i++;
            j--;
        }
        ans++;
    }
    cout<<ans;
    return 0;
}