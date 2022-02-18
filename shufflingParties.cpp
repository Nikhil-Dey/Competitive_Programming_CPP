#include<bits/stdc++.h>
using namespace std;


void shuffling(vector<int>& arr)
{
    int n = arr.size();
    
    for(int i = 1, j = n-1; i<n && j>=1; )
    {
        int a = i % 2;
        int b = arr[i] % 2;
        int c = j % 2 ;
        int d = arr[j] % 2;

        if((a==1 && b == 1) && ( c==0 && d == 0))
        {
            //cout<<arr[i]<<" "<<arr[j]<<endl;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
            continue;
        }

        if((a!=b) || (a!=1 || b!=1)){
            i++;
        }
        if((c!=d) || (c!=0 || b!=0)){
            j--;
        }
    }


}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n+1);
        for(int i = 1; i<n+1; i++)
        {
            cin>>arr[i];
        }
        shuffling(arr);
        /*
        for(int i = 1; i<n+1;i++ )
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        */
        int sum = 0;
        for(int i = 1; i<n+1; i++)
        {
            int a = i%2;
            int b = arr[i] % 2;
            if(a!=b)
                sum++;
        }
        cout<<sum<<endl;
    }
}