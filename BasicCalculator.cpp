#include<bits/stdc++.h>
using namespace std;
#define LL long long


int calculate(string s)
{
    stack<pair<int,int>> st;
    LL sum = 0;
    int sign = +1;

    for(int i = 0; i<s.length(); i++)
    {
        if(isdigit(s[i])){
            
            LL num = 0;
            while(i<s.length() && isdigit(s[i]))
            {
                num = (num * 10) + (s[i] - '0');
                i++;
            }
            i--;
            sum += (num * sign);
            sign = +1;
        }else if(s[i] == '('){

            pair<int,int> p(sum,sign);
            st.push(p);
            sum = 0;
            sign = +1;
        }else if(s[i] == ')'){

            LL x = st.top().first;
            int signature = st.top().second;
            sum = x + (signature * sum);
            st.pop();
        }else if(s[i] == '-'){
            sign = (-1 * sign);
        }
    }
    return sum;
}


int main()
{
    string s;
    getline(cin, s);
    int ans = calculate(s);
    cout<<ans<<endl;
}