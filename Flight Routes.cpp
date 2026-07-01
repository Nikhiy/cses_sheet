#include<bits/stdc++.h>
using namespace std;
int fun(vector<long long>& arr,long long num){
    int n=arr.size();
    int i=0,j=n-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(arr[mid]<=num) i=mid+1;
        else j=mid-1;
    }
    return i;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> arr(m,vector<int>(3,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            int temp;
            cin>>temp;
            arr[i][j]=temp;
        }
    }
    vector<vector<pair<int,long long>>> adj(n);
    for(auto it:arr){
        long long u=it[0]-1,v=it[1]-1,c=it[2];
        adj[u].push_back({v,c});
    }
    vector<vector<long long>> dist(n);
    dist[0].push_back(0);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [dis,node]=pq.top();
        pq.pop();
        if(dist[node].size()==k && dis > dist[node].back())
            continue;
        for(auto it:adj[node]){
            int adjnode=it.first;
            long long adjdis=it.second;
            long long newdis=1LL*dis+adjdis;
            if(dist[adjnode].size()<k){
                pq.push({newdis,adjnode});
                dist[adjnode].push_back(newdis);
                sort(dist[adjnode].begin(),dist[adjnode].end());
            }
            else{
                // sort(dist[adjnode].begin(),dist[adjnode].end());
                if(dist[adjnode].back()>newdis){
                    int ind=fun(dist[adjnode],newdis);
                    dist[adjnode].insert(dist[adjnode].begin()+ind,newdis);
                    dist[adjnode].pop_back();  
                    pq.push({newdis,adjnode});
                }
            }
        }
    }
    sort(dist[n-1].begin(),dist[n-1].end());
    for(int i=0;i<dist[n-1].size() && i<k;i++){
        cout<<dist[n-1][i]<<'\n';
    }
    return 0;
}