#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> adj(n);
    vector<int> in(n,0);
    for(auto it:arr){
        int u=it[0]-1,v=it[1]-1;
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    vector<int> topo;
    for(int i=0;i<n;i++){
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            in[it]--;
            if(in[it]==0) q.push(it);
        }
    }
    vector<int> dp(n,0);
    dp[0]=1;
    for(auto u:topo){
        for(auto it:adj[u]){
            dp[it]=(dp[it]+dp[u])%MOD;
        }
    }
    cout<<dp[n-1];
    return 0;
}