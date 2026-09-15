#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> pre(n+1);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^arr[i-1];
    }
    vector<vector<int>> query(q,vector<int>(2));
    for(int i=0;i<q;i++){
        for(int j=0;j<2;j++){
            cin>>query[i][j];
        }
    }
    for(auto it:query){
        int u=it[0],v=it[1];
        cout<<(pre[v]^pre[u-1])<<endl;
    }
    return 0;
}