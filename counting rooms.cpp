#include<bits/stdc++.h>
using namespace std;
int px[4]={0,0,-1,1};
int py[4]={1,-1,0,0};
void dfs(int x,int y,vector<vector<char>>& arr,vector<vector<int>>& vis){
    int n=arr.size();
    int m=arr[0].size();
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+px[i];
        int ny=y+py[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && arr[nx][ny]=='.'){
            dfs(nx,ny,arr,vis);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            arr[i][j]=c;
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && arr[i][j]=='.'){
                ans+=1;
                dfs(i,j,arr,vis);
            }
        }
    }
    cout<<ans;
    return 0;
}