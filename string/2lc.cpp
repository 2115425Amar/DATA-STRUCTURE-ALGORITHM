// 2559. Count Vowel Strings in Ranges

class Solution {
public:
    bool valid(string words) {
        int n = words.size() - 1;
        if ((words[0] == 'a' || words[0] == 'e' || words[0] == 'i' ||
             words[0] == 'o' || words[0] == 'u') &&
            (words[n] == 'a' || words[n] == 'e' || words[n] == 'i' ||
             words[n] == 'o' || words[n] == 'u')) {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            if (valid(words[i])) {
                v[i] = 1;
            } else {
                v[i] = 0;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << v[i] << " ";
        // }

        vector<int> ans;

        for (int j = 0; j < queries.size(); j++) {
            int c = 0;
            for (int k = queries[j][0]; k <= queries[j][1]; k++) {
                if (v[k] == 1) {
                    c++;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};

// -----------------------------------------------------------------------------------------------


// 560. Subarray Sum Equals K
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;

        int sum = 0;
        int c = 0;
        mpp[sum] = 1;

        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
            if (mpp.find(sum - k) != mpp.end()) {
                c += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return c;
    }
};