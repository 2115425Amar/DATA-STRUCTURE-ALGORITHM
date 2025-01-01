// leeetcode 49. Group Anagrams

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();

        map<string, vector<string>> mpp;
        for (int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(strs[i]);
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
// -------------------------------------------------------------------------------


// 1422. Maximum Score After Splitting a String

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zero = 0;
       
        int maxi = 0;
        
        for (int i = 0; i < n-1; i++) {
            if(s[i]=='0'){
                zero++;
            }
             int one = 0;
            for(int j=i+1; j<n; j++){
                if(s[j]=='1'){
                    one++;
                }
            }
            maxi = max(maxi, one+zero);
        }
        return maxi;
    }
};