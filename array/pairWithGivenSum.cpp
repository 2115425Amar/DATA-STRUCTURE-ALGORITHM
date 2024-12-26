// Two Sum - Pair with Given Sum ------->gfg

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        
        unordered_map<int, int>mpp;
        
        for(int i=0; i<n; i++){
            int rem = target-arr[i];
            
            if(mpp.find(rem)!=mpp.end()){
                return true;
            }
            mpp[arr[i]]++;
        }
        
        return false;
    }
};

