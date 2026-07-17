#include<bits/stdc++.h>
using namespace std;
int fun(int x,int y,vector<vector<char>>& arr){
    int n=arr.size();
    int m=arr[0].size();
    if(x==n-1 && y==m-1) return arr[n-1][m-1];
    if(x+1<n && y+1<m){
        char r=arr[x][y+1],d=arr[x+1][y];
        if(r<d){
            return arr[x][y]+fun(x,y+1,arr);
        }
        else if(r>d){
            return arr[x][y]+fun(x+1,y,arr);
        }
        else{
            return arr[x][y]+min(fun(x+1,y,arr),fun(x,y+1,arr));
        }
    }
    if(x+1<n) return arr[x][y]+fun(x+1,y,arr);
    if(y+1<m) return arr[y][y]+fun(x,y+1,arr);
    return 0;
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
    int temp=fun(0,0,arr);
    return 0;
}