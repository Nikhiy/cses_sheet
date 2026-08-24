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
    vector<info*> seg;
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int ind,int low,int high,)
}
int main(){
    int n;
    string s;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        s+=c;
    }
    SGTree s(n);
    s.build()
    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;

    }
}