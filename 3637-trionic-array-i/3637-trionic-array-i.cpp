class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        // the increasing sequence
        while(i+1<n && nums[i]<nums[i+1])i++;
        if(i==0 || i==n-1)return false;
        int peak=i;
        //the decreasing sequence
        while(i+1<n && nums[i]>nums[i+1])i++;
        if(i==peak || i==n-1)return false;
        peak=i;
        //the increasing again
        while(i+1<n && nums[i]<nums[i+1])i++;
    
        return i==n-1;
    }
};