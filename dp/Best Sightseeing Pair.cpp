// 1014. Best Sightseeing Pair
// https://www.youtube.com/watch?v=eQ1TdlglnY0
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN;
        int n=values.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum =  values[i] + values[j] + i - j;
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};

// ---------------------------------------------------------------------

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> v(n, 0);
        v[0] = values[0] + 0;

        for (int i = 1; i < n; i++) {
            v[i] = max(values[i] + i, v[i - 1]);
            // cout << v[i] << " ";
        }

        int res = 0;

        for (int j = 1; j < n; i++) {
            res = max(res, values[j] - j + v[i - 1]);
        }

        return res;
    }
};