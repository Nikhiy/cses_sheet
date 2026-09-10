#include <bits/stdc++.h>
using namespace std;
class Disjoint{
    public:
    vector<int> parent,size;
    Disjoint(int n){
        parent.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionBySize(int n1,int n2){
        int p1=findParent(n1);
        int p2=findParent(n2);
        if(p1==p2) return;
        if(size[p1]>size[p2]){
            parent[p2]=p1;
            size[p1]+=size[p2];
        }
        else if(size[p2]>size[p1]){
            parent[p1]=p2;
            size[p2]+=size[p1];
        }
        else{
            parent[p2]=p1;
            size[p1]+=size[p2]; 
        }
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    int prev=-1,cnt=n;
    Disjoint dis(n+1);
    while(q--){
        int u,v;
        cin>>u>>v;
        int p1=dis.findParent(u);
        int p2=dis.findParent(v);
        if(p1==p2){
            cout<<cnt<<' ';
            cout<<dis.size[dis.findParent(prev)]<<'\n';
            continue;
        }
        dis.unionBySize(u,v);
        cnt--;
        cout<<cnt<<' ';
        int p1s=dis.size[dis.findParent(p1)],p2s=dis.size[dis.findParent(p2)];
        if(prev==-1){
            if(p1s>p2s){
                cout<<p1s<<'\n';
                prev=dis.findParent(p1);
            }
            else{
                cout<<p2s<<'\n';
                prev=dis.findParent(p2);
            }
            continue;
        }
        int maxi=dis.size[prev];
        if(maxi>p1s && maxi>p2s){
            cout<<maxi<<'\n';
        }
        else if(p2s<p1s){
            cout<<p1s<<'\n';
            prev=dis.findParent(p1);
        }
        else{
            cout<<p2s<<'\n';
            prev=dis.findParent(p2);
        }
    }
    return 0;
}