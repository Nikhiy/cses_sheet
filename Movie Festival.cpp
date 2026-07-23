#include <bits/stdc++.h>
using namespace std;
static bool comp(vector<int>& a,vector<int>& b){
    if(a[1]!=b[1]) return a[1]<b[1];
    return a[0]<b[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++) for(int j=0;j<2;j++) cin>>arr[i][j];
    sort(arr.begin(),arr.end(),comp);
    vector<vector<int>> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i][0]<temp.back()[1]){
            continue;
        }
        else{
            temp.push_back(arr[i]);
        }
    }
    cout<<temp.size();
    return 0;
}