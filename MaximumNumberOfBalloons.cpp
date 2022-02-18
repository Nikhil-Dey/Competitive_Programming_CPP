#include<bits/stdc++.h>
using namespace std;

int maxNumberofBalloons(string text){
    map<char, int> m;
    for(int i = 0; i<text.length(); i++)
    {
        m[text[i]]++;
    }
    int ans = 0;
    //if(m['l']%2 == 0 && m['0']%2 == 0)
    ans = min(m['b'],min(m['a'],min(m['l']/2,min(m['o']/2,m['n']))));
    return ans;
}


int main(){
    string s;
    cin>>s;
    int ans = maxNumberofBalloons(s);
    cout<<ans<<endl;
}

