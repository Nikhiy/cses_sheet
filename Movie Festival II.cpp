#include <bits/stdc++.h>
using namespace std;
static bool comp(vector<int>& a,vector<int>& b){
    if(a[1]!=b[1]) return a[1]<b[1];
    return a[0]<b[0];
}
int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    int n,x;
    cin>>n>>x;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    sort(arr.begin(),arr.end(),comp);
    int ans=0;
    for(int i=0;i<n;i++){
        if(pq.size()<x){
            pq.push(arr[i][1]);
            ans++;
        }
        else{
            if(pq.top()<=arr[i][0]){
                pq.pop();
                pq.push(arr[i][1]);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}