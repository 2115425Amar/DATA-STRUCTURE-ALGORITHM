// 42. Trapping Rain Water

class Solution {
public:

void solveLeft(vector<int>& height, vector<int>&left_max){
        int n=height.size();
        int maxi = height[0];

        for(int i=0; i<n; i++){
            maxi = max(maxi, height[i]);
            left_max[i]=maxi;
        }
} 

void solveRight(vector<int>& height, vector<int>&right_max){
     int n=height.size();
     int maxi =0;

     for(int i=n-1; i>=0; i--){
        maxi = max(maxi, height[i]);
        right_max[i]=maxi;
     }
} 
   int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left_max(n);
        vector<int>right_max(n);

        solveLeft(height, left_max);
        solveRight(height, right_max);

        for(int i=0; i<n; i++){
            cout<<left_max[i]<<" ";
        }
        cout<<"->";
        for(int i=0; i<n; i++){
            cout<<right_max[i]<<" ";
        }

        int ans=0;
        for(int i=0; i<n; i++){
            ans+=min(left_max[i], right_max[i]) - height[i];
        }

        return ans;
    }
};