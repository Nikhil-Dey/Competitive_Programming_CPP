#include<bits/stdc++.h>
using namespace std;

// 2156. Find Substring With Given Hash Value

pair<bool,string> subStr(string s, string &currStr, int modulo, int k, int index, vector<unsigned long long> &hashTable, int &currHash, int hashValue)
{
    //cout<<currHash<<" "<<currStr<<endl;
    if(currHash == hashValue && currStr.length() == k){
        return {true, currStr};
    }
    
    if(index >= s.length() ){
        return {false, ""};
    }
    
    currStr.push_back(s[index]);
    currHash = (currHash % modulo + hashTable[index] % modulo) % modulo;
    pair<bool, string> a = subStr(s, currStr, modulo, k, index + 1, hashTable, currHash, hashValue);
    if(a.first){
        return a;
    }
    
    currStr.pop_back();
    currHash = (currHash % modulo - hashTable[index] % modulo) % modulo;
    
    pair<bool, string> b = subStr(s, currStr, modulo, k, index + 1, hashTable, currHash, hashValue);
    if(b.first){
        return b;
    }
    return {false, ""};
}

int powerFunction(int n, int i, int modulo){
    if(i == 0){
        return 1;
    }

    if(i == 1){
        return n;
    }

    if(i&1){
        int y = (int)((i-1)/2);
        int x = powerFunction(n, ((i-1)/2), modulo);
        return ((n % modulo) * ((x % modulo)* (x % modulo)) % modulo) % modulo;
    }else{
        int y = (int)(i/2);
        int x = powerFunction(n, (i/2), modulo);
        return ((x % modulo) * (x % modulo)) % modulo;
    }
}


string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    vector<unsigned long long> hashTable(s.length(), 0);
    for(int i = 0; i<s.length(); i++){
        hashTable[i] = ((((s[i] - 'a') + 1) % modulo) * (powerFunction(power, i, modulo) % modulo)) % modulo;
        //cout<<hashTable[i]<<" ";
    }//cout<<endl;

    string currStr;
    int currHash = 0;
    pair<bool, string> flag = subStr(s, currStr, modulo, k, 0, hashTable, currHash, hashValue);
    return flag.second;
}

int main(){
    string s;
    cin>>s;
    int power, modulo, k, hashValue;
    cin>>power>>modulo>>k>>hashValue;
    string ans = subStrHash(s, power, modulo, k, hashValue);
    cout<<ans<<endl;
}