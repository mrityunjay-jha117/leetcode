class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<tuple<int, int, int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int l = i+1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    ans.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                } else if (sum > 0)
                    r--;
                else
                    l++;
            }
        }
        vector<vector<int>> temp;
        for (auto& it : ans) {
            int x = get<0>(it);
            int y = get<1>(it);
            int z = get<2>(it);
            temp.push_back({x, y, z});
        }
        return temp;
    }
};