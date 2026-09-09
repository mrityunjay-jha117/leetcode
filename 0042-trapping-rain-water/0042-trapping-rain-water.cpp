class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int lmax = nums[l];
        int rmax = nums[r];
        int ans=0;
        while(l<=r){
            lmax=max(lmax,nums[l]);
            rmax=max(rmax,nums[r]);
            ans+=min(lmax,rmax)-min(nums[l],nums[r]);
            if(lmax>rmax)r--;
            else l++;
        }
        return ans;
    }
};