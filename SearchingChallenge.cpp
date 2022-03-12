#include<bits/stdc++.h>
using namespace std;


int isPalindrome(int num)
{

    int n, k, rev = 0;

    n = num;

    while (num != 0) {
        k = num % 10;
        rev = (rev * 10) + k;
        num = num / 10;
    }

    if (n == rev) {
        return 1;
    }
    else {
        return 0;
    }
}

int SearchingChallenge(int num){
    while(!isPalindrome(num)){
        num = num + 1;
    }
    return num;
}

int main(){
    int n;
    cin>>n;
    int ans = SearchingChallenge(n);
    cout<<ans<<endl;
}