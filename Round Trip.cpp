#include<bits/stdc++.h>
using namespace std;
bool fun(int node,int parent,vector<vector<int>>& adj,vector<int>& vis,map<int,int>& mpp,int& startnode,int& lastnode){
    vis[node]=1;
    mpp[node]=parent;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(fun(it,node,adj,vis,mpp,startnode,lastnode)){
                return true;
            }
        }
        else{
            if(parent!=it){
                startnode=it;
                lastnode=node;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<vector<int>> arr(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            int temp;
            cin>>temp;
            arr[i][j]=temp-1;
        }
    }
    for(auto it:arr){
        int u=it[0],v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n,0);
    map<int,int> mpp;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int lastnode=-1;
            int startnode=-1;
            bool temp=fun(i,-1,adj,vis,mpp,startnode,lastnode);
            if(temp){
                int node=lastnode;
                while(startnode!=node){
                    ans.push_back(node);
                    node=mpp[node];
                }
                ans.push_back(startnode);
                reverse(ans.begin(),ans.end());
                ans.push_back(startnode);
                cout<<ans.size()<<'\n';
                for(int i=0;i<ans.size();i++){
                    cout<<ans[i]+1<<'\n';
                }
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}