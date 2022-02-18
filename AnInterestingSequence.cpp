#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int ans = 0;
        while(x % 2 == 0){
            ans++;
            x = x / 2;
        }
        cout<<ans<<endl;
    }
}