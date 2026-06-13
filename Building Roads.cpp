#include<bits/stdc++.h>
using namespace std;
class Disjoint{
    public:
    vector<int> parent,rank;
    Disjoint(int n){
        parent.resize(n,0);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int node1,int node2){
        if(node1==node2) return;
        int p1=findParent(node1);
        int p2=findParent(node2);
        if(p1==p2) return;
        if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }
        else if(rank[p2]>rank[p1]){
            parent[p1]=p2;
        }
        else{
            rank[p1]+=1;
            parent[p2]=p1;
        }
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m,vector<int>(2));
    for(int i=0;i<m;i++){
        vector<int> temparr(2);
        for(int j=0;j<2;j++){
            int temp;
            cin>>temp;
            temparr[j]=temp-1;
        }
        arr[i]=temparr;
    }
    Disjoint dis(n);
    vector<int> vis(n,0);
    for(int i=0;i<arr.size();i++){
        dis.unionByRank(arr[i][0],arr[i][1]);
    }
    set<int> roots;
    for(int i=0;i<n;i++){
        roots.insert(dis.findParent(i));
    }
    vector<int> comp;
    for(int x:roots){
        comp.push_back(x);
    }
    vector<vector<int>> ans;
    int cnt=comp.size();
    if(cnt==1){
        int val=0;
        cout<<val<<'\n';
        return 0;
    }
    for(int i=1;i<comp.size();i++){
        ans.push_back({comp[i-1],comp[i]});
    }
    int val=ans.size();
    cout<<val<<'\n';
    for(int i=0;i<val;i++){
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << '\n';
    }
    return 0;
}