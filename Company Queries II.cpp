#include <bits/stdc++.h>
using namespace std;
void fun(int node,vector<vector<int>>& adj,vector<int>& dist){
    queue<pair<int,int>> q;
    q.push({0,node});
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
    return;
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> dp(n+1,vector<int>(20,-1));
    vector<int> dept(n+1,1e9);
    dept[1]=0;
    for(int i=1;i<n;i++){
        int a=i+1,b;
        cin>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        dp[a][0]=b;
    }
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1) dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    fun(1,adj,dept);
    while(q--){
        int a,b;
        cin>>a>>b;
        int d1=dept[a],d2=dept[b];
        if(d1!=d2){
            int diff=abs(d1-d2);
            if(d1>d2){
                for(int i=0;i<20;i++){
                    if(diff & (1<<i)){
                        a=dp[a][i];
                    }
                }
            }
            else{
                for(int i=0;i<20;i++){
                    if(diff & (1<<i)){
                        b=dp[b][i];
                    }
                }
            }
        }
        if(a==b){
            cout<<a<<' ';
            continue;
        }
        for(int j=19;j>=0;j--){
            int u=dp[a][j],v=dp[b][j];
            if(u!=v){
                a=u;
                b=v;
            }
        }
        cout<<dp[a][0]<<' ';
    }
    return 0;
}