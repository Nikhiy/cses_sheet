#include<bits/stdc++.h>
using namespace std;
static bool comp(vector<int>& a,vector<int>& b){
    if(a[0]!=b[0]) return a[0]<b[0];
    return a[1]<b[1];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u;
        cin>>v;
        arr.push_back({u,v,i});
    }
    sort(arr.begin(),arr.end(),comp);
    vector<int> ans(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int room=1;
    for(int i=0;i<n;i++){
        if(pq.empty()){
            pq.push({arr[i][1],room});
            ans[arr[i][2]]=room;
            room++;
        }
        else if(pq.top().first>=arr[i][0]){
            pq.push({arr[i][1],room});
            ans[arr[i][2]]=room;
            room++;
        }
        else{
            auto it=pq.top();
            pq.pop();
            ans[arr[i][2]]=it.second;
            pq.push({arr[i][1],it.second});
        }
    }
    cout<<room-1<<'\n';

    for(auto it:ans){
        cout<<it<<' ';
    }
    return 0;
}