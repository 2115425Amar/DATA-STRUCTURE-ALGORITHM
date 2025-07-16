class Solution {
public:
void merge(vector<int>& nums,int mid,int low,int high){
        int i,j;
        vector<int> ans(high-low+1);
        i=low,j=mid+1;
        int k=0;
        while(i<=mid && j<=high){
            if(nums[i]<nums[j]){
                ans[k++]=nums[i++];
            }else{
                ans[k++]=nums[j++];
            }
        }
        while(i<=mid){
             ans[k++]=nums[i++];
        }
        while(j<=high){
              ans[k++]=nums[j++];
        }
        for(int i=0;i<ans.size();i++){
            nums[low+i]=ans[i];
        }
    }
    void ms(vector<int>& nums,int low,int high){
        int mid;
        if(low<high){
            mid=(low+high)/2;
            ms(nums,low,mid);
            ms(nums,mid+1,high);
            merge(nums,mid,low,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        ms(nums,0,nums.size()-1);
        return nums;
    }
};