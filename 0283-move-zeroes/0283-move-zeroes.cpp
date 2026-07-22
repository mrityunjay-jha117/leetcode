class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        while(l<n && nums[l]!=0){
            l++;
        }
        for(int r=l;r<n;r++){
            if(nums[r]!=0){
                swap(nums[l++],nums[r]);
            }
        }   
 }
};