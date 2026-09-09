class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int k = 0;
        int n = nums.size();
        while (k < n) {
            if (nums[k] == val) {
                k++;
                continue;
            }
            swap(nums[k], nums[i]);
            i++;
            k++;
        }
        return i;
    }
};