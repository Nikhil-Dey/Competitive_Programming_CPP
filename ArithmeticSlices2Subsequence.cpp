#include<bits/stdc++.h>
using namespace std;
#define LL long long

int numberOfArithmeticSlices(vector<int>& A){
    int n = A.size();
    LL ans = 0;
    vector<map<LL,int>> cnt(n);
    for(int i = 1; i<n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            LL delta = (LL)A[i] - (LL)A[j];
            int sum = 0; 
            if(cnt[j].find(delta) != cnt[j].end())
            {
                sum = cnt[j][delta];
            }
            cnt[i][delta] += sum + 1;
            ans += sum;
            //cout<<ans<<" ";
        }
        //cout<<endl;
    }
    /*
    for(int i = 0; i<n ; i++)
    {
        for(int j = 0; j<cnt[i].size(); j++)
        {
            cout<<cnt[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    return (int) ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n ; i++)
    {
        cin>>arr[i];
    }
    int ans = numberOfArithmeticSlices(arr);
    cout<<ans<<endl;
}
