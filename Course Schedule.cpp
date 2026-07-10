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
    vector<vector<int>> adj(n);
    vector<int> in(n,0);
    queue<int> q;
    vector<int> ans;
    for(auto it:arr){
        int u=it[0]-1,v=it[1]-1;
        adj[u].push_back(v);
        in[v]++;
    }
    for(int i=0;i<n;i++){
        if(in[i]==0){
            // ans.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto it:adj[node]){
            in[it]--;
            if(in[it]==0){
                // ans.push_back(it);
                q.push(it);
            }
        }
    }
    if(ans.size()!=n){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<'\n';
    }
    return 0;
}