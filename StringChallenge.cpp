#include<bits/stdc++.h>
using namespace std;

void StringChallenge(string& str, int& num){

    for(int i = 0; i<str.length(); i++){
        if(isalpha(str[i])){
            char v;
            if(isupper(str[i])){
                v = 'A';
            }else{
                v = 'a';
            }
            int x = str[i] - v;
            int y = (x + num) % 26;
            char c = v + y;
            //cout<<x<<" "<<y<<" "<<c<<endl;
            str[i] = c;
        }
    }
}


int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    StringChallenge(s, n);
    cout<<s<<endl;
}