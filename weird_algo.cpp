#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> ans;
    ans.push_back(n);
    while(n!=1){
        if(n%2==0){
            n=1LL*n/2;
            ans.push_back(n);
        }
        else{
            n=1LL*n*3;
            n=1LL*n+1;
            ans.push_back(n);
        }
    }
    for(int i=0;i<ans.size();i++){
        if(i!=ans.size()-1) cout<<ans[i]<<" ";
        else cout<<ans[i];

    }
    return 0;
}