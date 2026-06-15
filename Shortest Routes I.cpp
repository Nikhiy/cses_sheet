#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    vector<vector<int>> arr(m,vector<int>(3,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            int temp;
            cin>>temp;
            arr[i][j]=temp;
        }
    }
    for(auto it:arr){
        int u=it[0]-1,v=it[1]-1,wt=it[2];
        adj[u].push_back({v,wt});
    }
    // vector<int> vis(n,0);
    // vis[0]=1;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,0});
    vector<long long> dist(n,LLONG_MAX);
    dist[0]=0;
    while(!pq.empty()){
        auto [dis,node]=pq.top();
        pq.pop();
        // int node=it.second;
        // int dis=it.first;
        if(dist[node]<dis) continue;
        for(auto it:adj[node]){
            long long adjdis=it.second;
            int adjnode=it.first;
            if(dist[adjnode]>1LL*dis+adjdis){
                dist[adjnode]=1LL*dis+adjdis;
                pq.push({1LL*dis+adjdis,adjnode});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<'\n';
    }
    return 0;
}