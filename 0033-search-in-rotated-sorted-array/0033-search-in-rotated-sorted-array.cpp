class Solution {
public:
    int f(vector<int>& nums, int i, int j, int target) {
        int low = i, high = j;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int temp = -1;

        int last = nums[n - 1];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > last) {
                temp = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int a = f(nums, 0, temp, target);
        int b = f(nums, temp + 1, n - 1, target);

        return a != -1 ? a : b;
    }
};