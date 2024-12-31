class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        
        int n=arr.size();
        sort(arr.begin(), arr.end());
        
        int currCons = 1;
        int maxCons = 1;
        
        for(int i=1; i<=n; i++){
            if(arr[i]==arr[i-1]+1){
                currCons++;
            }
            else if(arr[i]!=arr[i-1]){
                maxCons=max(maxCons, currCons);
                currCons=1;
            }
        }
        return maxCons;
    }
};
