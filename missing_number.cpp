#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> arr;
    int temp;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    int siz=arr.size();
    int i=0,j=siz-1;
    while(i<=j){
        int mid=(i+j)/2;
        if(arr[mid]==mid+1){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    cout<< i+1;
    return 0;
}