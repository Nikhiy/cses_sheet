#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m, vector<int>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    vector<long long> dist(n,1e18);
    vector<long long> ways(n,0),maxi(n,0),mini(n,1e9);
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:arr){
        int u=it[0]-1,v=it[1]-1,wt=it[2];
        adj[u].push_back({v,wt});
    }
    priority_queue<
    pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>
> pq;
    pq.push({0,0});
    dist[0]=0;
    ways[0]=1;
    maxi[0]=0;
    mini[0]=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        long long dis=it.first;
        int node=it.second;
        if(dist[node]<dis) continue;
        for(auto it:adj[node]){
            int adjnode=it.first;
            long long adjdis=it.second;
            long long newdis=dis+adjdis;
            if(newdis<dist[adjnode]){
                dist[adjnode]=newdis;
                pq.push({newdis,adjnode});
                ways[adjnode]=ways[node];
                maxi[adjnode]=maxi[node]+1;
                mini[adjnode]=mini[node]+1;
            }
            else if(newdis==dist[adjnode]){
                ways[adjnode]=(ways[adjnode]+ways[node])%MOD;
                maxi[adjnode]=max(maxi[adjnode],maxi[node]+1);
                mini[adjnode]=min(mini[adjnode],mini[node]+1);
            }
        }
    }
    cout<<dist[n-1]<<" ";
    cout<<ways[n-1]<<" ";
    cout<<mini[n-1]<<" ";
    cout<<maxi[n-1]<<" ";
    return 0;
}