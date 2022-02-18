#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n>>a;
        int m = sqrt(n);
        int ans = m*a;
        cout<<ans<<endl;
    }
}