#include<bits/stdc++.h>
using namespace std;
class SGTree{
    public:
    vector<long long> seg;
    SGTree(int n){
        seg.resize(4*n+1,0);
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
    long long query(int ind,int low,int high,int l,int r){
        //not inserting
        if(high<l || r<low) return 0;
        //complete mix
        if(l<=low && high<=r) return seg[ind];
        int mid=(low+high)/2;
        long long left=query(2*ind+1,low,mid,l,r);
        long long right=query(2*ind+2,mid+1,high,l,r);
        return left+right;
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> queries(q,vector<int>(2,-1));
    for(int i=0;i<q;i++){
        for(int j=0;j<2;j++){
            cin>>queries[i][j];
        }
    }
    SGTree s(n);
    s.build(0,0,n-1,arr);
    for(auto it:queries){
        long long ans=s.query(0,0,n-1,it[0]-1,it[1]-1);
        cout<<ans<<endl;
    }
    return 0;
}