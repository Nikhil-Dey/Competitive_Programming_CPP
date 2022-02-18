#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,l;
        cin>>n>>k>>l;
        int* arr = new int[n];
        for(int i = 0;i<n; i++)
        {
            cin>>arr[i];
        }
        int maxIndex = -1;
        int maxm = INT_MIN;
        for(int i = 0 ; i<n-1; i++)
        {
            if(arr[i] > maxm)
            {
                maxm = arr[i];
                maxIndex = i;
            }
        }
        int maxInject = l/k;
        if(k >=0)
        {
            if(arr[n-1] + (maxInject * k) > maxm)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }else{
            if(arr[n-1] > maxm)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }      

    }
}