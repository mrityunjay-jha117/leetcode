class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        int ans=0;
        for(auto num:mp){
            if(mp.count(num-1))continue;
            int cnt=0;
            int temp=num;
            while(mp.count(temp)){
                cnt++;
                temp++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};