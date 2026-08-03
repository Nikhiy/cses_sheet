#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]+1<<' ';
    }
    return 0;
}