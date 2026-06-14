#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1<<'\n';
        cout<<1<<'\n';
        return 0;
    }
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
    vector<int> vis(n,0);
    q.push(0);
    vis[0]=1;
    map<int,int> mpp;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==n-1) break;
        for(auto it:adj[node]){
            if(!vis[it]){
                mpp[it]=node;
                q.push(it);
                vis[it]=1;
            }
        }
    }
    if(mpp.find(n-1)==mpp.end()){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    int node=n-1;
    while(node!=0){
        ans.push_back(node);
        node=mpp[node];
    }
    ans.push_back(0);
    // reverse(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]+1<<'\n';
    }
    return 0;
}