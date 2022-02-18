#include<bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> nums, int start, int end, int target){
    if(start > end){
        return -1;
    }

    int mid = start + (end - start)/2;
    if(nums[mid] >= target){
        if((nums[mid] == target) && (mid == 0 || nums[mid - 1] != nums[mid])){
            return mid;
        }
        return firstOccurrence(nums, start, mid-1, target);
    }
    else {
        return firstOccurrence(nums, mid+1, end, target);
    }
}

int lastOccurrence(vector<int> nums, int start, int end, int target){
    if(start > end){
        return -1;
    }

    int mid = start + (end - start)/2;
    if(nums[mid] <= target){
        if((nums[mid] == target) && (mid == nums.size() - 1 || nums[mid + 1] != nums[mid])){
            return mid;
        }
        return lastOccurrence(nums, mid + 1, end, target);
    }
    else {
        return lastOccurrence(nums, start, mid - 1, target);
    }
}


vector<int> searchRange(vector<int>& nums, int target){
    int first = firstOccurrence(nums, 0, nums.size() - 1, target);
    int last = lastOccurrence(nums, 0, nums.size() - 1, target);
    return {first,last};
}

int main(){
    
}