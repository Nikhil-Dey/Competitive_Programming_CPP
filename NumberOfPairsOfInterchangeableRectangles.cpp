#include<bits/stdc++.h>
using namespace std;




long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    int n = rectangles.size();
    vector<float> ratio(n);
    for(int i = 0; i<n; i++)
    {
        ratio[i] = (float) rectangles[i][0] / (float) rectangles[i][1];
    }
    sort(ratio.begin(), ratio.end());
    int sum = 0;
    int count = 0;
    float newNumber = ratio[0];
    for(int i = 1; i<n; i++)
    {
        if(ratio[i] == newNumber)
        {
            count++;
        }
        else{
            int x,y;
            if(count%2 == 0){
                x = count/2;
                y = count+1;
            }
            else{
                x = (count+1)/2;
                y = count;
            }
            sum += (x*y);
            count = 0;
            newNumber = ratio[i];
        }
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i = 0; i<n; i++){
        arr[i] = new int[2];
    }
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    int ans = interchangeableRectangles(arr,n);
    cout<<ans<<endl;
}