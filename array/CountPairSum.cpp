// https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int,int>mpp;
        
        int n=arr.size();
        int c=0;
        
        for(int i=0; i<n; i++){
            int rem = target-arr[i];
            
            if(mpp.find(rem)!=mpp.end()){
                c+=mpp[rem];
            }
            mpp[arr[i]]++;
        }
        
        return c;
    }
};

// -------------------------------------------------------------------------------------------

// leetcode 1. Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int more=target-a;
            if(mpp.find(more)!=mpp.end()){
                return {mpp[more],i};
            }
            mpp[a]=i;
        }
        return{-1,-1};
    }
};