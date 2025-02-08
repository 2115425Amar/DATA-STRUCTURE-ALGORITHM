class Solution {
    public:
        int solve(vector<int> &arr, int n, int target, int i) {
                if (i >= n) {
                        return (target == 0) ? 1 : 0;
                }
                if (target < 0) {
                        return 0;
                }

                int take = solve(arr, n, target - arr[i], i + 1);
                int nottake = solve(arr, n, target, i + 1);

                return take + nottake;
        }

        int perfectSum(vector<int>& arr, int sum) {
                int n = arr.size();
                int ans = solve(arr, n, sum, 0);
                return ans;
        }
};
