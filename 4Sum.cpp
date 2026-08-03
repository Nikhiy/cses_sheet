#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr[i]={temp,i};
    }
    sort(arr.begin(),arr.end());
    for(int j=0;j<n;j++){
        for(int i=j+1;i<n;i++){
        int l=i+1,r=n-1;
        while(l<r){
            int temp=arr[i].first+arr[j].first+arr[l].first+arr[r].first;
            if(temp==x){
                cout<<arr[j].second+1<<' '<<arr[i].second+1<<' '<<arr[l].second+1<<' '<<arr[r].second+1;
                return 0;
            }
            else if(temp<x){
                l++;
            }
            else{
                r--;
            }
        }
    }
    }
    cout << "IMPOSSIBLE";
    return 0;
}