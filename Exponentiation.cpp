#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
int main(){
    int n;
    cin>>n;
    while(n--){
        long long a,b;
        cin>>a>>b;
        if(b==0){
            cout<<1<<endl;
            continue;
        }
        long long ans=1;
        while(b){
            if(b%2==1){
                ans=(ans*a)%MOD;
                b--;
            }
            a=(a*a)%MOD;
            b=b/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}