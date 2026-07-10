#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> in(n,0);
    vector<vector<int>> adj(n);
    for(auto it:arr){
        int u=it[0]-1,v=it[1]-1;
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(in[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            in[it]--;
            if(in[it]==0) q.push(it);
        }
    }
    vector<int> dp(n,-1);
    vector<int> parent(n,-1);
    dp[0]=1;
    for(int i:ans){
        if(dp[i]==-1) continue;
        for(auto it:adj[i]){
            if(dp[it]<1+dp[i]){
                dp[it]=1+dp[i];
                parent[it]=i;
            }
        }
    }
    vector<int> fin;
    int node=n-1;
    while(node!=-1){
        fin.push_back(node);
        node=parent[node];
    }
    if(dp[n-1]==-1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    reverse(fin.begin(),fin.end());
    cout<<fin.size()<<"\n";
    for(auto it:fin){
        cout<<it+1<<" ";
    }
    return 0;
}