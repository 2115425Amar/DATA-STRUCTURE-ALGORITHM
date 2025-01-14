// 2270. Number of Ways to Split Array

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int c = 0;

        vector<long long>LtoR(n,0);
        vector<long long>RtoL(n,0);
        long long sum=0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            LtoR[i]=sum;
        }
        sum=0;
        for(int i=n-1; i>=0; i--){
            sum+=nums[i];
            RtoL[i]=sum;
        }

        for(int i=0; i<n-1; i++){
            if(LtoR[i] >= RtoL[i+1]){
                c++;
            }
        }

        return c;
    }
};

// ---------------------------------------------------------------

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for (int i = 0; i < n - 1; i++) {
            int leftsum = 0;
            for (int j = 0; j <= i; j++) {
                leftsum += nums[j];
                // cout<<nums[j]<<" ";
            }
            // cout<<endl;
            int rightsum = 0;
            for (int j = i + 1; j < n; j++) {
                rightsum += nums[j];
            }

            if (leftsum >= rightsum) {
                c++;
            }
        }
        return c;
    }
};

---------------------------------------------------------------