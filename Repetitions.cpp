#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=0;
    int temp=0;
    char prev='0';
    for(char c:s){
        if(c==prev){
            temp+=1;
        }
        else{
            ans=max(temp,ans);
            temp=1;
            prev=c;
        }
    }
    ans=max(ans,temp);
    cout<<ans;
    return 0;
}