#include<bits/stdc++.h>
using namespace std;
int fun(int node,vector<int>& vis,vector<vector<int>>& adj,vector<int>& ans){
    vis[node]=1;
    int val=0;
    for(auto it:adj[node]){
        if(!vis[it]){
            val=val+1+fun(it,vis,adj,ans);
        }
    }
    ans[node]=val;
    return val;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n-1;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    vector<vector<int>> adj(n+1);
    for(int i=0;i<arr.size();i++){
        adj[arr[i]].push_back(i+2);
    }
    vector<int> ans(n+1,0);
    vector<int> vis(n+1,0);
    int temp=fun(1,vis,adj,ans);
    ans[1]=temp;
    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}