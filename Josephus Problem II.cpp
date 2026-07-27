#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    vector<int> ans;
    while(!q.empty()){
        for(int i=0;i<m;i++){
            auto it=q.front();
            q.pop();
            q.push(it);
        }
        ans.push_back(q.front());
        q.pop();
    }
    for(auto it:ans){
        cout<<it<<' ';
    }
    return 0;
}