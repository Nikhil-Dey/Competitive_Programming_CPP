#include<bits/stdc++.h>
using namespace std;

int findPeakElements(vector<int> nums, int start, int end){
    if(start == end){
        return start;
    }
    
    cout<<start<<" "<<end<<endl;
    int mid = start + (end - start) / 2;
    if (nums[mid] > nums[mid + 1]){
        return findPeakElements(nums, start, mid);
    }else {
        return findPeakElements(nums, mid + 1, end);
    }
}

int findPeakElement(vector<int>& nums) {
    return findPeakElements(nums, 0, nums.size() - 1);
}


int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0 ;i < n; i++){
        cin>>nums[i];
    }
    int ans = findPeakElement(nums);
    cout<<ans<<endl;
}