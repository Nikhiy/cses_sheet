#include<bits/stdc++.h>
using namespace std;
static bool comp(vector<int>& a,vector<int>& b){
    return a[2]<b[2];
}
class Disjoint{
    public:
    vector<int> rank,parent;
    Disjoint(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int n1,int n2){
        int p1=findParent(n1);
        int p2=findParent(n2);
        if(p1==p2) return;
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else if(rank[p2]>rank[p1]){
            parent[p1]=p2;
        }
        else{
            parent[p2]=p1;
            rank[p1]+=1;
        }
    }
};
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    Disjoint dis(n+1);
    vector<vector<int>> arr(m,vector<int>(3,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    long long ans=0;
    sort(arr.begin(),arr.end(),comp);
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u=arr[i][0];
        int v=arr[i][1];
        int w=arr[i][2];
        int p1=dis.findParent(u);
        int p2=dis.findParent(v);
        if(p1!=p2){
            ans+=w;
            dis.unionByRank(u,v);
        }
    }
    set<int> st;
    for(int i=1;i<=n;i++){
        int p=dis.findParent(i);
        st.insert(p);
    }
    if(st.size()>1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<ans;
    return 0;
}