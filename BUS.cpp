#include<bits/stdc++.h>
using namespace std;

void solve(int n,int m, int q){
    int* arr = new int [n+1];
    for(int i = 0; i<=n; i++)
    {
        arr[i] = 0;
    }
    int count = 0;
    bool flag = 0;
    char* c = new char[q];
    int* a = new int[q];
    for(int i = 0; i<q; i++)
    {
        cin>>c[i]>>a[i];
    }
    for(int i = 0; i<q; i++)
    {
        if(c[i] == '+')
        {
            if(arr[a[i]] == 1)
            {
                flag = 1;
                break;
            }
            else{
                arr[a[i]] = 1;
                count++;
            }
        }
        else{
            if(arr[a[i]] == 1){
                count--;
                arr[a[i]] = 0;
            }
            else{
                flag = 1;
                break;
            }
        }

        if(count > m)
        {
            flag = 1;
            break;
        }
        
    }
    if(flag)
        cout<<"Inconsistent"<<endl;
    else
        cout<<"Consistent"<<endl;
    delete [] arr;
    delete [] a;
    delete [] c;
    return;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        solve(n,m,q);
    }
}