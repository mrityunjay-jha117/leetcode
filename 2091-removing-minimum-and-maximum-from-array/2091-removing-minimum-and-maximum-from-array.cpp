class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int l=min_element(nums.begin(),nums.end())-nums.begin();
        int r=max_element(nums.begin(),nums.end())-nums.begin();
        int n=nums.size();
        //left
        int left=max(l,r)+1;
        //right
        int right=max(n-l,n-r);
        //both
        int both=n-abs(r-l)+1;
        return min({left,right,both});
    }
};