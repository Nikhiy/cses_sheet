#include<bits/stdc++.h>
using namespace std;
int findlast(int arr,vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> dist(n,1e9);
    queue<pair<int,int>> q;
    q.push({0,arr});
    dist[arr]=0;
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
void fun(int pre,vector<vector<int>>& adj,vector<int>& dist){
    int n=adj.size();
    dist[pre]=0;
    queue<pair<int,int>> pq;
    pq.push({0,pre});
    while(!pq.empty()){
        auto [dis,node]=pq.front();
        pq.pop();
        if(dist[node]<dis) continue;
        for(auto it:adj[node]){
            int newdis=dis+1;
            if(dist[it]>newdis){
                pq.push({newdis,it});
                dist[it]=newdis;
            }
        }
    }
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
    int node=findlast(0,adj);
    int last=findlast(node,adj);
    vector<int> dist1(n,1e9),dist2(n,1e9);
    fun(node,adj,dist1);
    fun(last,adj,dist2);
    for(int i=0;i<n;i++){
        int temp=max(dist1[i],dist2[i]);
        cout<<temp<<" ";
    }
    return 0;
}