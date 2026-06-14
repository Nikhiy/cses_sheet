#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m,vector<int>(2));
    for(int i=0;i<m;i++){
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
    queue<int> q;
    vector<int> color(n,-1);
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            q.push(i);
            vis[i]=1;
            color[i]=0;
            while(!q.empty()){
                int node=q.front();
                int pcolor=color[node];
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                        color[it]=!color[node];
                    }
                    else{
                        if(color[it]==color[node]){
                            cout<<"IMPOSSIBLE";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     if(color[i]==0) color[i]=2;
    // }
    for(int i=0;i<n;i++){
        cout<<color[i]+1<<'\n';
    }
    return 0;
}