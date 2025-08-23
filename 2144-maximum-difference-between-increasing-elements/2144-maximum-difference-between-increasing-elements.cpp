class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int mini=nums[0];
        for(int i=1;i<n;i++){
            mini=min(mini,nums[i]);
            ans=max(ans,nums[i]-mini);
        }
        return (!ans)?-1:ans;
    }
};