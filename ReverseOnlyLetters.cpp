#include<bits/stdc++.h>
using namespace std;

string reverseOnlyLetters(string s){
    for(int i = 0, j = s.length() - 1; i<=j;)
    {
        if(((s[i]>='A' && s[i] <= 'Z')||(s[i]>='a' && s[i]<='z'))&&((s[j]>='A' && s[j]<='Z')||(s[j]>='a' && s[j]<='z'))){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
            continue;
        }
        if(!((s[i]>='A' && s[i] <= 'Z')||(s[i]>='a' && s[i]<='z')))
            i++;
        
        if(!((s[j]>='A' && s[j]<='Z')||(s[j]>='a' && s[j]<='z')))
            j--;
    }
    return s;
}



int main(){
    string s;
    cin>>s;
    string c = reverseOnlyLetters(s);
    cout<<c<<endl;
}