#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> dist(n,-1e18);
    vector<vector<int>> arr(m,vector<int>(3));
    vector<vector<pair<int,int>>> adj(n);
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
    dist[0]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(dist[i]==-1e18) continue;
            for(auto it:adj[i]){
                int v=it.first;
                int wt=it.second;
                dist[v]=max(dist[v],dist[i]+wt);
            }
        }
    }
    vector<int> bad(n,0);
    for(auto it:arr){
        int u=it[0]-1,v=it[1]-1,wt=it[2];
        if(dist[u]==-1e18) continue;
        if(dist[u]+wt>dist[v]){
            bad[v]=1;
        }
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(bad[i]==1) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto v:adj[node]){
            int it=v.first;
            if(bad[it]==0){
                q.push(it);
                bad[it]=1;
            }
        }
    }
    if(bad[n-1]) cout<<-1<<"\n";
    else cout<<dist[n-1]<<"\n";
    return 0;
}