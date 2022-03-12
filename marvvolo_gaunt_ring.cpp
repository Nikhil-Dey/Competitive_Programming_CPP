#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    ll query[3];
    for(int i = 0; i<3; i++){
        cin>>query[i];
    }

    vector<ll>arr (n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int y = 3;
    vector<vector<ll>>  dp(n+1, vector<ll> (y));

    dp[0][0] = LLONG_MIN; 
    dp[0][1] = LLONG_MIN;
    dp[0][2] = LLONG_MIN;

    for(int i = 0 ; i<3; i++){
        for(int j = 1; j<=n; j++){

            ll x;
            if(i == 0){
                x = 0;
            }else{
                x = dp[j][i - 1];
            }

            dp[j][i] = max(dp[j-1][i], (ll)((ll)(query[i]*arr[j-1]) + (ll)x));
        }
    }

    cout<<dp[n][2]<<endl;
}