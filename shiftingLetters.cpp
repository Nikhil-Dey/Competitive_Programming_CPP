#include<bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<int>& shifts) {
    int n = s.length();
    string c;
    for(int i = n-2; i>=0 ;i--)
    {
        shifts[i] += shifts[i+1];
        shifts[i] %= 26;
    }

    for(int i = 0; i<n ; i++)
    {
        int x = s[i] - 'a';
        c += 'a' + (x + shifts[i])%26;
    }
    return c;
}


int main()
{
    string s;
    cin>>s;
    int n = s.length();
    vector<int> arr(n);
    for(int i = 0 ; i<n;i++){
        cin>>arr[i];
    }
    string c = shiftingLetters(s,arr);
    cout<<c<<endl;     

}