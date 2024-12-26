//  LC 494. Target Sum
class Solution {
public:
int solve(vector<int>& nums, int target, int sum, int ind){
    int n = nums.size();
    if(ind == n){
        if(sum == target){
            return 1;
        }else{
            return 0;
        }
    }
    int inc = solve(nums, target, sum-nums[ind], ind+1);
    int exc = solve(nums, target, sum+nums[ind], ind+1);

    return inc + exc;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        int ind = 0;
        
        return solve(nums, target, sum, ind);

    }
};