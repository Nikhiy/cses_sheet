#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int diff=target-arr[i];
        if(mpp.find(diff)!=mpp.end()){
            int ind=mpp[diff];
            cout<<ind+1<<' '<<i+1;
            return 0;
        }
        mpp[arr[i]]=i;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}