#include<bits/stdc++.h>
using namespace std;
int fun(int x,int y,vector<vector<char>>& arr){
    if()
}
int main(){
    string ans;
    int n;
    cin>>n;
    vector<vector<char>> arr(n,vector<char>(n));
    for(int i=0;in;i++){
        for(int j=0;j<n;j++){
            char temp;
            cin>>temp;
            arr[i][j]=temp;
        }
    }
    // int i=0,j=0;
    // while(i!=n-1 && j!=n-1){
    //     ans+=arr[i][j];
    //     char right='Z';
    //     char down='Z';
    //     if(i+1<n){
    //         down=arr[i+1][j];
    //     }
    //     if(j+1<n){
    //         right=arr[i][j+1];
    //     }
    //     if(down>right)
    // }
    int temp=fun(0,0,arr);
    return 0;
}