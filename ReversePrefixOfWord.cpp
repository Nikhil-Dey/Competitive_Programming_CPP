#include<iostream>
#include<string>
using namespace std;
void reverseString(string& s, int index){
    for(int i = 0, j = index; i<=j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    //cout<<s<<endl;
}

int searchIndex(string s, char c){
    for(int i = 0; i<s.length(); i++)
    {
        if(s[i] == c){
            return i;
        }
    }
    return -1;
}

int main()
{
    string s;
    cin>>s;
    char c;
    cin>>c;
    int index = searchIndex(s,c);
    if(index != -1)
        reverseString(s, index);
    cout<<s<<endl;
}