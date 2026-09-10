#include<bits/stdc++.h>
using namespace std;
class SGTree{
    public:
    vector<int> seg;
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
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }
    int query(int ind,int low,int high,int l,int r){
        //full join
        if(l<=low && high<=r) return seg[ind];
        //no join
        if(high<l || r<low) return INT_MAX;
        int mid=(low+high)/2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
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
        int ans=s.query(0,0,n-1,it[0]-1,it[1]-1);
        cout<<ans<<endl;
    }
}