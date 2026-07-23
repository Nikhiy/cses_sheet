#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    multiset<int> st;
    for(auto it:a) st.insert(it);
    for(int i=0;i<m;i++){
        auto it=st.upper_bound(b[i]);
        if(it==st.begin()){
            cout<<-1<<'\n';
            continue;
        }
        --it;
        cout<<*it<<'\n';
        st.erase(it);
    }
    return 0;
}