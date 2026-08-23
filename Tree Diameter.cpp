#include<bits/stdc++.h>
using namespace std;
int findlast(int pre,vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> dist(n,1e9);
    queue<pair<int,int>> q;
    q.push({0,pre});
    dist[pre]=0;
    while(!q.empty()){
        auto [dis,node]=q.front();
        q.pop();
        if(dist[node]<dis) continue;
        for(auto it:adj[node]){
            int newdis=dis+1;
            if(dist[it]>newdis){
                q.push({newdis,it});
                dist[it]=newdis;
            }
        }
    }
    int maxi=dist[0],node=0;
    for(int i=0;i<n;i++){
        if(dist[i]>maxi){
            maxi=dist[i];
            node=i;
        }
    }
    return node;
}
int fun(int pre,vector<vector<int>>& adj,vector<int>& vis,vector<int>& dist){
    int n=adj.size();
    vis[pre]=1;
    int temp=0;
    for(auto it:adj[pre]){
        if(!vis[it]){
            temp=max(temp,1+fun(it,adj,vis,dist));
        }
    }
    return dist[pre]=temp;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++){
        for(int j=0;j<2;j++){
            int temp;
            cin>>temp;
            arr[i][j]=temp-1;
        }
    }
    vector<vector<int>> adj(n);
    for(auto it:arr){
        int u=it[0],v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n,0);
    vector<int> dist(n,0);
    int node=findlast(0,adj);
    int ans=fun(node,adj,vis,dist);
    cout<<ans;
    return 0;
}