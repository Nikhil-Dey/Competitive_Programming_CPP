#include<bits/stdc++.h>
using namespace std;

int calculateCount(int N, string Str){

    int count = 0, rem = 0, x = 0;
    for(int i = 0; i<N; i++){
        rem = 0;
        for(int j = i; j<N; j++){
            x = Str[j] - '0';
            if(i == j && x == 0){
                count++;
                break;
            }

            if(x % 2 == 0 && (rem + x) % 3 == 0){
                count++;
            }
            rem = rem+x % 3;
        }
    }
    return count;
}

int main(){
    int n;
    string s;
    cin>>n>>s;
    cout<<calculateCount(n, s)<<endl;
}