#include <bits/stdc++.h>
using namespace std;
class SGTree{
    public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int low,int high,vector<int>& arr,int orr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr,!orr);
        build(2*ind+2,mid+1,high,arr,!orr);
        if(orr) seg[ind]=seg[2*ind+1] | seg[2*ind+2];
        else seg[ind]=seg[2*ind+1] ^ seg[2*ind+2];
        return;
    }
    void update(int ind,int low,int high,int i,int val,int orr){
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid){
            update(2*ind+1,low,mid,i,val,!orr);
        }
        else{
            update(2*ind+2,mid+1,high,i,val,!orr);
        }
        if(orr) seg[ind]=seg[2*ind+1] | seg[2*ind+2];
        else seg[ind]=seg[2*ind+1] ^ seg[2*ind+2];
    }
};
int main(){
    int n,q;
    cin>>n>>q;
    int el=pow(2,n);
    vector<int> arr(el);
    for(int i=0;i<el;i++) cin>>arr[i];
    SGTree s(el);
    if(n%2==0) s.build(0,0,el-1,arr,0);
    else s.build(0,0,el-1,arr,1);
    while(q--){
        int i,val;
        cin>>i>>val;
        i--;
        if(n%2==0) s.update(0,0,el-1,i,val,0);
        else s.update(0,0,el-1,i,val,1);
        cout<<s.seg[0]<<endl;
    }
}