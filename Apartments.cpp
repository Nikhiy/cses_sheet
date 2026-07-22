#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),h(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>h[i];
    }
    sort(a.begin(),a.end());
    sort(h.begin(),h.end());
    int i=0,j=0;
    int ans=0;
    while(i<n && j<m){
        if(a[i]>h[j]){
            if(h[j]>=a[i]-k && h[j]<=a[i]+k){
                ans++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        else{
            if(h[j]>=a[i]-k && h[j]<=a[i]+k){
                ans++;
                i++;
                j++;
            }
            else {
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}