#include<bits/stdc++.h>
using namespace std;
int start=-1,end=-1;
bool fun(int node,vector<vector<int>>& adj,vector<int>& vis,map<int,int>& mpp){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            mpp[node]=it;
            auto i=fun(it,adj,vis,mpp);
            if(i==true) return true;
            mpp.erase(node);
        }
        else{
            if(mpp.find(it)!=mpp.end()){
                start=node;
                end=it;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m,vector<int>(2,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> adj(n);
    for(auto it:arr){
        int u=it[0]-1;
        int v=it[1]-1;
        adj[u].push_back(v);
    }
    vector<int> vis(n,0);
    map<int,int> mpp;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            mpp[i]=i;
            auto it=fun(i,adj,vis,mpp);
            if(it){
                while(mpp.find(start)!=mpp.end() && mpp[start]!=end){
                    ans.push_back(start);
                    start=mpp[start];
                }
                ans.push_back(end);
                ans.push_back(start);
                cout<<ans.size()<<'\n';
                for(auto it:ans){
                    cout<<it+1<<'\n';
                }
                return 0;
            }
            mpp.erase(i);
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}