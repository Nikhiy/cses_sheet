#include<bits/stdc++.h>
using namespace std;
int px[4]={0,0,-1,1};
int py[4]={1,-1,0,0};
string ans="";
// string valid(string& a,string& b){
//     if(a=="") return b;
//     if(a.size()<b.size()) return a;
//     return b;
// }
// void fun(int x,int y,string& temp,vector<vector<char>>& arr,vector<vector<int>>& vis){
//     int n=arr.size();
//     int m=arr[0].size();
//     if(arr[x][y]=='B'){
//         ans=valid(ans,temp);
//         return;
//     }
//     vis[x][y]=1;
//     for(int i=0;i<4;i++){
//         int nx=x+px[i];
//         int ny=y+py[i];
//         if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && (arr[nx][ny]=='.' || arr[nx][ny]=='B')){
//             if(i==0){
//                 temp+='R';
//                 fun(nx,ny,temp,arr,vis);
//                 temp.pop_back();
//             }
//             else if(i==1){
//                 temp+='L';
//                 fun(nx,ny,temp,arr,vis);
//                 temp.pop_back();
//             }
//             else if(i==3){
//                 temp+='U';
//                 fun(nx,ny,temp,arr,vis);
//                 temp.pop_back();
//             }
//             else{
//                 temp+='D';
//                 fun(nx,ny,temp,arr,vis);
//                 temp.pop_back();
//             }
//         }
//     }
//     vis[x][y]=0;
// }
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char temp;
            cin>>temp;
            arr[i][j]=temp;
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='A'){
                q.push({i,j});
                vis[i][j]=1;
                break;
            }
        }
    }
    map<pair<int,int>,pair<int,int>> parent;
    int fx=-1,fy=-1;
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        if(arr[x][y]=='B'){
            fx=x;
            fy=y;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=x+px[i];
            int ny=y+py[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && (arr[nx][ny]=='.' || arr[nx][ny]=='B')){
                vis[nx][ny]=1;
                q.push({nx,ny});
                parent[{nx,ny}]={x,y};
            }
        }
    }
    if(fx!=-1 && fy!=-1){
        int i=fx,j=fy;
        while(arr[i][j] != 'A'){
            auto [nx,ny] = parent[{i,j}];
            if(nx == i){
                if(ny > j){
                    ans += 'L';
                }
                else{
                    ans += 'R';
                }
            }
            else{
                if(nx > i){
                    ans += 'U';
                }
                else{
                    ans += 'D';
                }
            }
            i = nx;
            j = ny;
        }
    }
    reverse(ans.begin(),ans.end());
    if(fx!=-1 && fy!=-1){
        cout << "YES\n";
        cout << ans.size() << "\n";
        cout << ans << "\n";
        return 0;
    }
    cout<<"NO";
    return 0;
}