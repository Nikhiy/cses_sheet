#include<bits/stdc++.h>
using namespace std;
class SGTree{
    public:
    vector<long long> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int l,int r,vector<int>& arr){
        if(l==r){
            seg[ind]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*ind+1,l,mid,arr);
        build(2*ind+2,mid+1,r,arr);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    long long query(int ind,int left,int right,int l,int r){
        //no overlap
        if(right<l || r<left) return 0;
        //complete
        if(l<=left && right<=r) return seg[ind];
        int mid=(left+right)/2;
        long long low=query(2*ind+1,left,mid,l,r);
        long long high=query(2*ind+2,mid+1,right,l,r);
        return low+high;
    }
    void update(int ind,int l,int r,int idx,int val){
        if(l==r){
            seg[ind]=val;
            return;
        }
        int mid=(l+r)/2;
        if(mid>=idx){
            update(2*ind+1,l,mid,idx,val);
        }
        else{
            update(2*ind+2,mid+1,r,idx,val);
        }
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    SGTree s(n);
    vector<vector<int>> queries(q,vector<int>(3));
    s.build(0,0,n-1,arr);
    for(int i=0;i<q;i++){
        for(int j=0;j<3;j++){
            cin>>queries[i][j];
        }
    }
    for(auto it:queries){
        if(it[0]==1){
            s.update(0,0,n-1,it[1]-1,it[2]);
        }
        else{
            long long ans=s.query(0,0,n-1,it[1]-1,it[2]-1);
            cout<<ans<<endl;
        }
    }
    return 0;
}