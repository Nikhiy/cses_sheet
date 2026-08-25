#include <bits/stdc++.h>
using namespace std;
class info{
    public:
    int open,close,full;
    info(){
        open=0;
        close=0;
        full=0;
    }
    info(int o,int c,int f){
        open=o;
        close=c;
        full=f;
    }
};
class SGTree{
    public:
    vector<info> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }
    info merge(info a, info b){
        info ans;
        int newcomplete=min(a.open,b.close);
        ans.open=a.open+b.open-newcomplete;
        ans.close=a.close+b.close-newcomplete;
        ans.full=a.full+b.full+newcomplete;
        return ans;
    }
    void build(int ind,int low,int high,string& s){
        if(low==high){
            seg[ind]=info(s[low]=='(',s[low]==')',0);
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,s);
        build(2*ind+2,mid+1,high,s);
        seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
        return;
    }
    info query(int ind,int low,int high,int l,int r){
        if(high<l || r<low) return info();
        if(l<=low && high<=r) return seg[ind];
        int mid=(low+high)/2;
        info left=query(2*ind+1,low,mid,l,r);
        info right=query(2*ind+2,mid+1,high,l,r);
        return merge(left,right);
    }
};
int main(){
    string s;
    getline(cin,s);
    int n=s.size();
    SGTree sgt(n);
    sgt.build(0,0,n-1,s);
    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        info ans=sgt.query(0,0,n-1,l,r);
        cout<<ans.full*2<<'\n';
    }
    return 0;
}