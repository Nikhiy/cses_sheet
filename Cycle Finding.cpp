#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m,vector<int>(3));
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            int temp;
            cin>>temp;
            arr[i][j]=temp;
        }
    }
    for(auto it:arr){
        int u=it[0]-1,v=it[1]-1,wt=it[2];
        adj[u].push_back({v,wt});
    }
    vector<long long> dist(n,0);
    for(int k=0;k<n-1;k++){
        for(int i=0;i<n;i++){
            if(dist[i]==) continue;
            for(auto )
        }
    }
    return 0;
}