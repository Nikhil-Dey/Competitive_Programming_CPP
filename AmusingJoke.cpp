// https://codeforces.com/problemset/problem/141/A

#include <iostream>
#include <string>
#include<vector>
using namespace std;

void calculateAlphabets(string names, vector<int>& letters){
    for (int i = 0; i<names.length(); i++){
        int x = names[i] - 'A';
        letters[x]++;
    }
}

int main(){
    string host, guest, piledLetters;
    cin>>host>>guest>>piledLetters;
    vector<int> totalLetters(27,0);
    vector<int> totalPiledLetters(27,0);
    calculateAlphabets(host, totalLetters);
    calculateAlphabets(guest, totalLetters);
    calculateAlphabets(piledLetters, totalPiledLetters);
    bool flag = true;
    for (int i = 0; i<27; i++){
        if (totalLetters[i] != totalPiledLetters[i]){
            flag = false;
            cout<<"NO"<<endl;
            break;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }
}
