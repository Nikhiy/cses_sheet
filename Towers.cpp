#include <bits/stdc++.h>
using namespace std;
int fun(int val,vector<int>& arr){
    int n=arr.size();
    int i=0,j=n-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(arr[mid]>val) j=mid-1;
        else i=mid+1;
    }
    return i;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(temp.back()<=arr[i]){
            temp.push_back(arr[i]);
        }
        else{
            int ind=fun(arr[i],temp);
            temp[ind]=arr[i];
        }
    }
    cout<<(int) temp.size();
    return 0;
}