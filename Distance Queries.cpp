#include <bits/stdc++.h>
using namespace std;
void dij(vector<vector<int>>& adj,vector<int>& dist){
    int n=adj.size();
    queue<int> q;
    q.push(1);
    dist[1]=0;
    vector<int> vis(n+1,0);
    vis[1]=0;
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
                dist[it]=dist[node]+1;
                vis[it]=1;
            }
        }
    }
    return;
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> arr(n-1,vector<int>(2));
    vector<vector<int>> dp(n+1,vector<int>(20,-1));
    for(int i=0;i<n-1;i++){
        int a,b;
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
            if(0==j) a=arr[i][j];
            else b=arr[i][j];
        }
        // dp[a][0]=b;
        // dp[b][0]=a;
    }
    vector<vector<int>> adj(n+1);
    for(auto it:arr){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> dist(n+1,1e9);
    dij(adj,dist);
    for(int i=1;i<=n;i++){
        for(auto it:adj[i]){
            if(dist[i]==dist[it]+1){
                dp[i][0]=it;
                break;
            }
        }
    }
    dp[1][0] = -1;
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1) dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int a=dist[u],b=dist[v];
        if(a!=b){
            int diff=abs(a-b);
            if(a>b){
                for(int i=0;i<20;i++){
                    if(diff &(1<<i)){
                        u=dp[u][i];
                    }
                }
            }
            else{
                for(int i=0;i<20;i++){
                    if(diff &(1<<i)){
                        v=dp[v][i];
                    }
                }
            }
        }
        if(u==v){
            int dis=dist[u];
            int ans=a+b-2*dis;
            cout<<ans<<' ';
            continue;
        }
        for(int i=19;i>=0;i--){
            int uu=dp[u][i];
            int vv=dp[v][i];
            if(uu!=vv && uu!=-1 && vv!=-1){
                u=uu;
                v=vv;
            }
        }
        int dis=dist[dp[u][0]];
        int ans=a+b-2*dis;
        cout<<ans<<' ';
    }
    return 0;
}