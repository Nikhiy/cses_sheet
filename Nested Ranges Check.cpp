#include<bits/stdc++.h>
using namespace std;
static bool comp(vector<int>& x,vector<int>& y){
    if(x[0]==y[0]) return x[1]>y[1];
    return x[0]<y[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }
    sort(arr.begin(),arr.end(),comp);
    vector<int> a(n),b(n);
    int maxi=INT_MIN,mini=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i][1]>maxi){
            maxi=arr[i][1];
        }
        else{
            b[arr[i][2]]=1;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i][1]<mini){
            mini=arr[i][1];
        }
        else{
            a[arr[i][2]]=1;
        }
    }
    for(auto it:a){
        cout<<it<<' ';
    }
    cout<<'\n';
    for(auto it:b){
        cout<<it<<' ';
    }
    return 0;
}